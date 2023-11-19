using ConsoleApp1;
using System;
using System.Diagnostics;

Console.WriteLine("Enter a login: ");
string login = Console.ReadLine();
Console.WriteLine("Enter a password: ");
string pass = Console.ReadLine();
Console.WriteLine("Enter a cardnumber: ");
string cardnumber = Console.ReadLine();
Stopwatch stopwatch = new Stopwatch();

try {

    stopwatch.Start();
    StrelkaSelenium strelka = new StrelkaSelenium(cardnumber);

    var b = strelka.GetBalance();
    Console.WriteLine($"Ваш баланс: {b}");

    strelka.Authorization(login, pass);
    foreach (var i in strelka.balances)
        Console.WriteLine(i);
    foreach (var a in strelka.cardNames)
        Console.WriteLine(a);

    //strelka.GetCookies();

    stopwatch.Stop();
    //strelka.CloseWeb();
    StrelkaSelenium.KillProcesses();
    TimeSpan ts = stopwatch.Elapsed;

    string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
        ts.Hours, ts.Minutes, ts.Seconds,
        ts.Milliseconds / 10);
    Console.WriteLine(elapsedTime);
}
catch (Exception ex) {
    StrelkaSelenium.KillProcesses();
    Console.WriteLine("Возникла непредвиденная ошибка:");
    Console.WriteLine(ex);
}