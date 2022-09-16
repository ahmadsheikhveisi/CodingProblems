A utility class that creates an instance of several families of classes. It can also return a factory for a certain group.

The Factory Design Pattern is useful in a situation that requires the creation of many different types of objects, all derived from a common base type. The Factory Method defines a method for creating the objects, which subclasses can then override to specify the derived type that will be created. Thus, at run time, the Factory Method can be passed a description of a desired object (e.g., a string read from user input) and return a base class pointer to a new instance of that object. The pattern works best when a well-designed interface is used for the base class, so there is no need to cast the returned object. 


The idea is to use a static member-function (static factory method) that creates & returns instances, hiding the details of class modules from the user
