using System;

namespace someTest
{
    class Program
    {

        static void Main(string[] args)
        {
            //Console.WriteLine(ConstructorExample.unInitVar);
            //Console.WriteLine("\nsome code running in main\n");
            //ConstructorExample constructorExample;

            //constructorExample = new ConstructorExample();
            //constructorExample = new ConstructorExample();
            ConstructorChild constructorChild = new ConstructorChild();
            Console.WriteLine("\n\nprint from main " + ConstructorChild.unInitVar);
        }
    }

    class ConstructorExample
    {
        static public string unInitVar;
        public string unInitInstanceVar;
        static ConstructorExample()
        {
            unInitVar = "initialized in static constructor";
            Console.WriteLine("Static constructor working");
            Console.WriteLine(unInitVar + "FROM STATIC CONSTR\n\n");
        }

        public ConstructorExample()
        {
            unInitInstanceVar = "initialized in static Class creating object";
            Console.WriteLine("Class creating object constructor working\n\n");
        }
    }

    class ConstructorChild : ConstructorExample
    {
        static ConstructorChild()
        {
            unInitVar = "initialized in static constructor FROM CHILD";
            Console.WriteLine("Static constructor FROM CHILD working");
            Console.WriteLine(unInitVar + "FROM STATIC CONSTR CHILD\n\n");
        }

        public ConstructorChild()
        {
            unInitInstanceVar = "initialized in static Class creating object FROM CHILD";
            Console.WriteLine("Class creating object constructor working FROM CHILD\n\n");
        }
    }
}