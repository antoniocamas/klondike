===============
Design Patterns
===============

Command
-------
   
Movements classes are using the Command pattern.
::
   src/controller/movement/


Flyweight
---------

The Suit of each card is asigned using a Flyweight pattern.
::
   src/model/card/SuitFlyweightFactory.*

Chain Of Responsibility
-----------------------

Given and imput deciding the kind of movement is done with the chain of
responsibility pattern. Otherwise the there were a very ugly if..else block.
::
   src/model/movement/MovementClassf*

Builder
-------

Building a Chain of Resposibility is complicated and the client "MovementDescriber"
was getting complicated and very coupled.
::
   src/model/movement/MovementClassifierBuilder*

   
Memento
-------

In order to implement save/load undo/redo the patter Memento has been used.
The undo/redo could have been done with a Command pattern, but having to use
memento I decided to reuse it.
::
   src/model/Table*

   
Bridge
------

The feature save/load use the pattern bridge forseeing a future change of the
persisten technology.
::
   src/model/marsharll/*


Singleton
---------

The configuration instance is programed with a singleton. This singleton could be
reading a configuration file or a database, but I had no time to implement it.
::
   src/Configuration.*
