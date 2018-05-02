# Compiler
Prototype Of A Scripting Language Compiler
===



MainCompiler: main loop to get string and execute


Parser: split input string to words


Grammar: split words to substatement and connect them


Calculator: calculation rules in varied situation


Variable: store,declare and change variables


Vari: dynamic type for string and int


SubStateMent: statement splited by words such as "== > < ="


utils: some useful helper functions



Now Supporting plus,sub,declare,equal,gt,lt....
---



V1.01
---
1.Create Variable and Calculator.

2.Change char[] to string

V1.02
---
1.Create Vari and SubStateMent

2.String addition

3.New mode : bracket

V1.03
---
1.Set keywords

2.Refactor Grammar : Get result from SubStateMent

V1.04
---
1.Fix bugs in bracket mode and string mode

2.Failed to refactor vari by template or virtual

3.Fix bugs in Calculator

4.Finish GetVariable and "=" part of Connector

V1.05
---
1.Finish equalmode in connector

2.GetFinalResult by combine substatement one by one

3.Now keyword has priority

