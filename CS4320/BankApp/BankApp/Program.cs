using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Soap;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace BankApp
{
    internal class Program
    {
        static List<Account> accountsList = new List<Account>();
        static void SaveXMLFile(string FilePath)
        {
            IFormatter myFormatter = new SoapFormatter();
            Stream myStream = new FileStream(FilePath, FileMode.Create, FileAccess.Write, FileShare.None);

            myFormatter.Serialize(myStream, accountsList.ToArray());
            myStream.Close();
            Console.WriteLine("\nXML file has been saved.\n");
        }

        static void LoadXMLFile(string FilePath)
        {
            IFormatter myFormatter = new SoapFormatter();
            Stream myStream = new FileStream(FilePath, FileMode.Open, FileAccess.Read, FileShare.None);

            Account[] accArray = (Account[])myFormatter.Deserialize(myStream);
            accountsList.AddRange(accArray);
            myStream.Close();
            Console.WriteLine("\nXML file has been loaded.\n");
        }

        static void DisplayAccounts()
        {
            Console.WriteLine("Account No\t\tHolder Name\t\tBalance");
            Console.WriteLine("---------------------------------------------");

            for (int i = 0; i < accountsList.Count; i++)
            {
                Console.WriteLine("{0, -20}{1, -25}{2, -30}", accountsList[i].AccountNo, accountsList[i].HolderName, accountsList[i].Balance);
            }
        }

        static void AddAccount()
        {
            string accno;
            string name;
            decimal balance;

            Console.Write("Acct. No: ");
            accno = Console.ReadLine();

            Console.Write("Name: ");
            name = Console.ReadLine();

            Console.Write("Balance: ");
            balance = decimal.Parse(Console.ReadLine());

            Account acc = new Account(accno, name, balance);
            accountsList.Add(acc);
            Console.WriteLine("\n1 Account has been added\n");
        }

        static Account Find(string accno)
        {
            for (int i = 0; i < accountsList.Count; i++)
            {
                if (accountsList[i].AccountNo == accno)
                {
                    return accountsList[i];
                }
            }
            return null;
        }

        static void SearchAccount()
        {
            Console.Write("Acct. No? ");
            string accno = Console.ReadLine();
            Account selectedAccount = Find(accno);

            if(selectedAccount != null)
            {
                Console.WriteLine("\n{0, -20}, {1, -25}, {2, -30}\n", selectedAccount.AccountNo, selectedAccount.HolderName, selectedAccount.Balance);
            }
            else
            {
                Console.WriteLine("\nAccount is not found\n");
            }
        }

        static void DeleteAccount()
        {
            Console.Write("Acct. No? ");
            string accno = Console.ReadLine();
            Account selectedAccount = Find(accno);

            if (selectedAccount != null)
            {
                accountsList.Remove(selectedAccount);
            }
            else
            {
                Console.WriteLine("\nAccount is not found\n");
            }
        }

        static void EditAccount()
        {
            string name;
            decimal balance;

            Console.Write("Acct. No? ");
            string accno = Console.ReadLine();
            Account selectedAccount = Find(accno);

            if (selectedAccount != null)
            {
                Console.Write("Name: ");
                name = Console.ReadLine();

                Console.Write("Balance: ");
                balance = decimal.Parse(Console.ReadLine());

                selectedAccount.HolderName = name;
                selectedAccount.Balance = balance;
            }
            else
            {
                Console.WriteLine("\nAccount is not found\n");
            }
        }

        static Account isMin(Account current, Account loopCurrent)
        {
            if (current == null)
            {
                return loopCurrent;
            }
            else if (current.Balance > loopCurrent.Balance)
            {
                return loopCurrent;
            }
            else
            {
                return current;
            }
        }
        static Account isMax(Account current, Account loopCurrent)
        {
            if (current == null)
            {
                return loopCurrent;
            }
            else if (current.Balance < loopCurrent.Balance)
            {
                return loopCurrent;
            }
            else
            {
                return current;
            }
        }

        static void DisplayMinMaxTotal()
        {
            decimal total = 0;
            Account minAcct = null;
            Account maxAcct = null;

            for (int i = 0; i < accountsList.Count; i++)
            {
                total += accountsList[i].Balance;
                minAcct = isMin(minAcct, accountsList[i]);
                maxAcct = isMax(maxAcct, accountsList[i]);
            }

            Console.WriteLine("\nTotal Balance: ${0}.", total);
            Console.WriteLine("Account with Minimum Balance: {0} ({1}) - ${2}.", minAcct.HolderName, minAcct.AccountNo, minAcct.Balance);
            Console.WriteLine("Account with Maximum Balance: {0} ({1}) - ${2}.\n", maxAcct.HolderName, maxAcct.AccountNo, maxAcct.Balance);
        }

        static void SaveMinMaxTotal(string FilePath)
        {
            decimal total = 0;
            Account minAcct = null;
            Account maxAcct = null;

            for (int i = 0; i < accountsList.Count; i++)
            {
                total += accountsList[i].Balance;
                minAcct = isMin(minAcct, accountsList[i]);
                maxAcct = isMax(maxAcct, accountsList[i]);
            }

            StreamWriter fileWriter = new StreamWriter(FilePath);

            fileWriter.WriteLine("Total Balance: ${0}", total);
            fileWriter.WriteLine("Account with Minimum Balance: {0} ({1}) - ${2}.", minAcct.HolderName, minAcct.AccountNo, minAcct.Balance);
            fileWriter.WriteLine("Account with Maximum Balance: {0} ({1}) - ${2}.", maxAcct.HolderName, maxAcct.AccountNo, maxAcct.Balance);

            fileWriter.Close();
            Console.WriteLine("\nMin Max Total File has been saved.");
        }

        static int Menu()
        {
            int choice;

            Console.WriteLine("1-Load File");
            Console.WriteLine("2-Display Accounts");
            Console.WriteLine("3-Add account");
            Console.WriteLine("4-Search for account");
            Console.WriteLine("5-Delete account");
            Console.WriteLine("6-Edit account");
            Console.WriteLine("7-Save to File");
            Console.WriteLine("8-Compute Total, Maximum and Minimum Balances");
            Console.WriteLine("9-Save Total, Maximum and Minimum Balances to File");
            Console.WriteLine("10-Exit");

            Console.Write("Choice > ");
            choice = int.Parse(Console.ReadLine());

            return choice;
        }

        static void Main(string[] args)
        {
            int option;
            while((option = Menu()) != 10)
            {
                switch(option)
                {
                    case 1:
                        LoadXMLFile("Accounts.xml");
                        break;
                    case 2:
                        DisplayAccounts();
                        break;
                    case 3:
                        AddAccount();
                        break;
                    case 4:
                        SearchAccount();
                        break;
                    case 5:
                        DeleteAccount();
                        break;
                    case 6:
                        EditAccount();
                        break;
                    case 7:
                        SaveXMLFile("Accounts.xml");
                        break;
                    case 8:
                        DisplayMinMaxTotal();
                        break;
                    case 9:
                        SaveMinMaxTotal("MinMaxTotal.txt");
                        break;
                    default:
                        Console.WriteLine("Invalid input.");
                        break;
                }
            }
        }
    }
}
