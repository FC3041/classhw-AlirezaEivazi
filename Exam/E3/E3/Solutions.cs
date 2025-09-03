using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
namespace E3;
//q0
public class Animal
{
    public virtual string MakeSound()
    {
        return $"Some generic animal sound";
    }
}
public class Dog : Animal
{
    public override string MakeSound()
    {
        return $"Woof";
    }
}
//q1
public class MyPointType1
{

    public int X { get; set; }
    public int Y { get; set; }

}

public struct MyPointType2
{
    public int X { get; set; }
    public int Y { get; set; }

}
////Q2
//public class Comparer<T>(T a , T b)
//{

//}

//public class Product 
//{
//    public string Name { get; set; }
//    public int Price { get; set; }
//    public Product(string n, int price)
//    {
//        (Name, Price) = (n, price);
//    }
//}

public class ResourceManager : IDisposable
{
    public bool IsDisposed;
    public void Dispose()
    {
        IsDisposed = true;
    }
}

public class LinqProblems
{
public static List<int> FilterAndDouble(List<int> numbers)
    {
        numbers.Where(t => numbers[t] % 2 == 0 && numbers[t] > 5)
            .Select(t => numbers[t] * 2);
        //var result = numbers;
        return numbers;
    }

}

