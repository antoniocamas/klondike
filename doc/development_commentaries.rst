===================
Design commentaries
===================

The Design tries to follow some clean code and GRASP principles.

Klondike follows the MVC arquitecture.

1) Single Responsibility. In General all clases and methods intent to have a single responsibility, has well as low coupling and high coherence.

2) Open/Close. It has been a difficult principle to follow throught all the code. The code that may be extended in the future tryies to be closed to change and open to extension. But It is true that even so design patters used break this principle.

3) Liskov Substitution. Every Hierarchy follows this principle and polymorphism is heavily used.

4) Interface Segregation can be observed in View.h or TableLoaderImplementor.h

5) Dependency inversion, a double Dispatch technique has been used to avoid that the controllers are couple to the view. They just know the view interface.

6) Controller. There are controller classes for each event or use case.

7) Creator. Some clases have the single responsibility of creatin objects

8) There are several examples of dependency injection. (MenuText.h)


9) The card component has been design as if it where part of a library. The intention is to reuse for other card games.



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

The Suit of each card is assigned using a Flyweight pattern.
::
   src/model/card/SuitFlyweightFactory.*

Chain Of Responsibility
-----------------------

Given and input deciding the kind of movement is done with the chain of
responsibility pattern. Otherwise the there were a very ugly if..else block.
::
   src/model/movement/MovementClassf*

Builder
-------

Building a Chain of Responsibility is complicated and the client "MovementDescriber"
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

The feature save/load use the pattern bridge foreseeing a future change of the
persistent technology.
::
   src/model/marsharll/*


Singleton
---------

The configuration instance is programmed with a singleton. This singleton could be
reading a configuration file or a database, but I had no time to implement it.
::
   src/Configuration.*


Iterator
---------

The CardStack method "CardStackShowcase getCardsRepresenter() const;" follows the same
principles than the pattern Iterator. The implementation and the naming doesn't stick to the
design pattern since this part was programmed before the learning. I will refactor it if I have
time.
::
   src/model/card/CardStack*

Also the pattern Iterator is extensively used via the C++11 stl library.
