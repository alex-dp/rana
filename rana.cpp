/*Rana: a better syntax to markup*/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "helper.h"

using namespace std;

string infile = "\0", outfile = "\0", o_ext = "\0", tag_name = "";
int ignore = -1, mode = NEW_TAG;
char argfor = '0';
vector<string> tag_names;
bool quoting = false;

int main (int argc, char** argv){
	for(int i = 1; i < argc; i++) {		//ignore program name

		if (argv[i][0] != '-' && i != ignore) {		//if it's not an opt nor an arg then it's the infile
			infile = argv[i];
			ignore = -1;
		}

		else if (argfor != '0') {		//if it's an arg
			switch (argfor) {			//(what is it for)
				case 'o':
					outfile = argv[i];
					break;
				case 'e':
					o_ext = argv[i];
					break;
				default:
					cout << help();
					return WRONG_OPTION;
			}

			argfor = '0';				//then the next is not an arg
		}

		else {							//then it's an option

			if (req_arg(argv[i][1])){	//if opt requires an arg
				ignore = i + 1;			//the next is it
				argfor = argv[i][1];	//(keep in mind what for)
			} else {					//otherwise it's just an option

				switch (argv[i][1]) {
					case 'v':
						cout << VERSION << '\n';
						return 0;

					case 'h':
						cout << help();
						return 0;
						
					default:
						return WRONG_OPTION;
				}
			}
		}
	}

	if (infile == "\0") {		//if no input file is given
		cout << help();
		return 0;
	}

	if (outfile == "\0"){		//if no out is given
		if (has_suffix(infile, '.' + EXT))		//if it's a {productname} file
			outfile = split(infile, '.')[0] + (o_ext == "\0" ? ".html" : ('.' + o_ext));

		else if (is_markup(infile))				//if it's *ml
			outfile = split(infile, '.')[0] + '.' + EXT;

		else {
			cout << help();
			return WRONG_INPUT_FILE;
		}
	}

	//load input into a vector
	vector<unsigned char> v;
	if (FILE *fp = fopen(infile.c_str(), "r")) {
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);
		fclose(fp);
	}

	//open the output file, parse the input and write to output
	if(FILE *out = fopen(outfile.c_str(), "w")) {
		for (int i = 0; i < v.size(); i++) {
			switch (v.at(i)) {
				case '(':
					mode = ARGUMENTS;
					break;
				case '{':
					mode = CONTENT;
					break;
				case '}':
					mode = NEXT_TAG;
					break;
				case ')':
					mode = EXPECT_CONTENT;
					break;
				case '"':
					if (!is_escaped(v, i) && mode != ARGUMENTS)
						mode = QUOTING_INGORE_QUOTES;
					break;
				case ' ':
				case '\n':
				case '\t':
					if (mode != ARGUMENTS)
						mode = COPY;
					break;
				default:		//if it does not start a new token
					if (mode != ARGUMENTS)
						mode = NEW_TAG;
			}

			switch (mode) {
				case ARGUMENTS:
					if (v.at(i) == '(' && !quoting && v.at(i + 1) != ')')
						fprintf(out, " ");
					else if (v.at(i) != '(') fprintf(out, "%c", v.at(i));
					if (v.at(i) == '"' && !is_escaped(v, i))
						quoting = !quoting;
					break;
				case CONTENT:
					mode = COPY;
					break;
				case NEXT_TAG:
					fprintf(out, "%c%c%s%c", '<', '/', tag_names.at(tag_names.size() - 1).c_str(), '>');
					tag_names.pop_back();
					mode = COPY;
					break;
				case EXPECT_CONTENT:
					fprintf(out, "%c", '>');
					mode = COPY;
					break;
				case NEW_TAG:
					tag_name = "";
					try {
						while(v.at(i) != '(') {
							tag_name += v.at(i);
							i++;
						}
					} catch (...) {}
					tag_names.push_back(tag_name);
					fprintf(out, "%c%s", '<', tag_name.c_str());
					mode = COPY;
					i--;
					break;
				case QUOTING_INGORE_QUOTES:
					i++;
					while ((v.at(i) == '"' && is_escaped(v, i)) || v.at(i) != '"') {
						fprintf(out, "%c", v.at(i));
						i++;
					}
					break;
				case COPY:
					fprintf(out, "%c", v.at(i));
					break;
			}
		}
		fclose(out);
	}

	return 0;
}