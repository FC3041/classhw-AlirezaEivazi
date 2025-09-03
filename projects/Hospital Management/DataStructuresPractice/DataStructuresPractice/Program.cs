using System;
using System.Collections.Generic;
using System.Runtime.Intrinsics.X86;
using System.Security.Cryptography.X509Certificates;
using static System.Net.Mime.MediaTypeNames;
using System.IO;
using System.IO.Enumeration;
using System.ComponentModel.DataAnnotations;

class Patient
{
    public string ?FirstName { get; set; }
    public string ?LastName { get; set; }
    public string ?Disease { get; set; }
    public override string ToString()
    {
        return $"{FirstName}{LastName}-{Disease}";
    }
}

class Hospital
{
    MyQueue<Patient> WaitingList ;
    MyStack<Patient> InTreatment ;
    List<Patient> Treated ;
    public Hospital( )
    {
        WaitingList = new MyQueue<Patient>();
        InTreatment = new MyStack<Patient>();
        Treated = new List<Patient>();
        Patient p = new Patient();
        p.FirstName = "Alireza";
        p.LastName = "Eivazi";
        p.Disease = "...";
        AddToWaitingList(p);
}

    public void NextPatient()
    {
        if (WaitingList.Count == 0)
        {
            throw new InvalidOperationException("Waiting List is empty");
            
        }
        Patient P = WaitingList.DeQueue();
        InTreatment.Push(P);
        Console.WriteLine($"the patient is {P.FirstName} {P.LastName}");
    }
    public void FinishTreatment()
    {
        if (InTreatment.Count == 0)
        {
            throw new InvalidOperationException(" in treatment list is empty !");
        }
        Patient P = InTreatment.Pop();
        Treated.Add(P);
        Console.WriteLine($"the threated patient is {P.FirstName} {P.LastName}");
    }
    public void PrintWaitingList()
    {
        Console.WriteLine("the patients in Wating list are :");
        WaitingList.Print();
    }
    public void PrintInTreatment()
    {
        Console.WriteLine("the patients in treatment are :");
        InTreatment.Print();
    }
    public void PrintTreated()
    {
        Console.WriteLine("the patients were treated from this hospital are :");
        foreach(var p in Treated)
        {
            Console.WriteLine($"{p.FirstName} {p.LastName} _ {p.Disease}");
        }
    }   
    public void AddToWaitingList(Patient p)
    {
        WaitingList.EnQueue(p);
    }
    public void AddToInTreatment(Patient p)
    {
        InTreatment.Push(p);

    }
    public void AddToTreated(Patient P)
    {
        Treated.Add(P);
    }
    public void SavePatientsToFile(string FileName)
    {
        List<string> Lines = new List<string>();
        foreach(var p in Treated)
        {
            Lines.Add($"{p.FirstName}  {p.LastName} - {p.Disease}");
        }
        File.WriteAllLines(FileName, Lines); 
    }


}

class Program
{
    public static void Main(string[] args)
    {
        Hospital H = new Hospital();
        Console.WriteLine
        (
            "1.Add new patient\n2.See waiting list\n3.Send next patient to treatment\n4.Finish treatment\n5.See treated patients\n6. Save treated patients to file\n7.Exit"
        );
        while (true)
        {
            Console.Write("Select an option: \n");
            var input = Console.ReadLine();

            switch (input)
            {
                case "1":
                    Patient p = new Patient();
                    Console.WriteLine("please enter ur patient first name : ");
                    p.FirstName = Console.ReadLine();
                    Console.WriteLine("please enter ur patient lastname: ");
                    p.LastName = Console.ReadLine();
                    Console.WriteLine("please enter ur patient disease : ");
                    p.Disease = Console.ReadLine();
                    Console.WriteLine($"u added a new patient with this propetries\n{p.FirstName} {p.LastName} _ {p.Disease}");
                    H.AddToWaitingList(p);
                    break;
                case "2":
                    H.PrintWaitingList();
                    break;
                case "3":
                    H.NextPatient();
                    break;
                case "4":
                    H.FinishTreatment();
                    break;
                case "5":
                    H.PrintTreated();
                    break;
                case "6":
                    Console.WriteLine("please enter the filename that you want to save treated patients in :");
                    var filename = Console.ReadLine();
                    if (filename != null)
                        H.SavePatientsToFile(filename);
                    Console.WriteLine("Patients saved successfully!");
                    try
                    {
                        H.SavePatientsToFile(filename);
                        Console.WriteLine("Patients saved successfully!");
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Error saving file: {ex.Message}");
                    }
                    break;
                case "7":
                    Console.WriteLine("Exiting program...");
                    Environment.Exit(0);
                    break;

                default:
                    Console.WriteLine("Invalid option. Try again.");
                    break;

            }
        }
    }
}