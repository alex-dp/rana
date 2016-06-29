#Rana

Welcome to Rana, the project to give SGML a better look.

The syntax looks a lot more like C than markup:

	nest(){
		egg(age="2d"){}
		bird(){}
	}

becomes:

	&lt;nest&gt;
		&lt;egg age="2d"&gt;&lt;/egg&gt;
		&lt;bird&gt;&lt;/bird&gt;
	&lt;/nest&gt;

() and {} are mandatory, but that will change.

to try it out, compile main.cpp and run it with just a `.rn` file as input.