#Rana

Welcome to Rana, the project to give SGML a better look.

The syntax looks a lot more like C than markup:

	nest(){
		egg(age="2d"){}
		bird(){}
	}

becomes:

	<nest>
		<egg age="2d"></egg>
		<bird></bird>
	</nest>

() and {} are mandatory, but that will change.

to try it out, clone this repo and run INSTALL.sh

a markup to rana parser is probably on its way.

Rana is released under the GNU GPLv3, and comes with absolutely no warranty, not even the warranty of fitness for a particular purpose.