#Rana

Welcome to Rana, the project to give SGML a better look.

The syntax looks a lot more like C than markup:

<code>nest(){<br>
	egg(age="2d"){}<br>
	bird(){}<br>
}
</code>

becomes:

<code>
&lt;nest&gt;<br>
	&lt;egg age="2d"&gt;&lt;/egg&gt;<br>
	&lt;bird&gt;&lt;/bird&gt;<br>
&lt;/nest&gt;
</code>

() and {} are mandatory, but that will change.

to try it out, compile main.cpp and run it with just a `.rn` file as input.