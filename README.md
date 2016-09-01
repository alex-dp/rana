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

you can escape parsing with double quotes (`"`)

() and {} are mandatory, but that will change.

to compile and install, run `make && sudo make install`

a markup to rana parser is probably on its way.

Rana is released under the GNU GPLv3

Copyright (C) 2016 DP Development

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.