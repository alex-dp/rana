#Rana

Welcome to Rana, the project to give SGML a better look.

The syntax looks a lot more like C than markup:

<code>nest(){
	egg(age="2d"){}
	bird(){}
}</code>

becomes:

<code><nest>
	<egg age="2d"></egg>
	<bird></bird>
</nest></code>

() and {} are mandatory, but that will change.

to try it out, compile main.cpp and run it with just a `.rn` file as input.