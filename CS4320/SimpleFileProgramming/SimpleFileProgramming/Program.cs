// See https://aka.ms/new-console-template for more information
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace SimpleFileProgramming
{
    class Program
    {
        static List<Account> accountsList = new List<Account>();
        static void ReadFile(string FilePath)
        {
            StreamReader fileReader = new StreamReader(FilePath);
            string line;

            while( (line = fileReader.ReadLine()) != null)
            {
                //Console.WriteLine(line);
                string[] lineParts = line.Split(';');
                Account acc = new Account(lineParts[0], lineParts[1], decimal.Parse(lineParts[2]));

                accountsList.Add(acc);
            }
            fileReader.Close();
        }

        static void SaveFile(string FilePath)
        {
            StreamWriter fileWriter = new StreamWriter(FilePath);

            for (int i = 0; i < accountsList.Count; i++)
            {
                fileWriter.WriteLine("{0}; {1}; {2}", accountsList[i].AccountNo, accountsList[i].HolderName, accountsList[i].Balance);
            }
            fileWriter.Close();
            Console.WriteLine("\nFile has been saved.");
        }

        static void SaveBinaryFile(string FilePath)
        {
            IFormatter myFormatter = new BinaryFormatter();
            Stream myStream = new FileStream(FilePath, FileMode.Create, FileAccess.Write, FileShare.None);

            myFormatter.Serialize(myStream, accountsList);
            myStream.Close();
            Console.WriteLine("\nBinary file has been saved.\n");
        }

        static void LoadBinaryFile(string FilePath)
        {
            IFormatter myFormatter = new BinaryFormatter();
            Stream myStream = new FileStream(FilePath, FileMode.Open, FileAccess.Read, FileShare.None);

            accountsList = (List<Account>) myFormatter.Deserialize(myStream);
            myStream.Close();
            Console.WriteLine("\nBinary file has been loaded.\n");
        }

        static void DisplayAccounts()
        {
            Console.WriteLine("Account No\t\tHolder Name\t\tBalance");
            Console.WriteLine("---------------------------------------------");

            for(int i = 0; i < accountsList.Count; i++)
            {
                Console.WriteLine("{0, -20}{1, -25}{2, -30}", accountsList[i].AccountNo, accountsList[i].HolderName, accountsList[i].Balance);
            }
        }
        static void ApplyInterest()
        {
            for (int i = 0; i < accountsList.Count; i++)
            {
                accountsList[i].Balance *= 1.02m; //interest rate is 2%
            }
        }

        static void Main(string[] args)
        {
            /* ReadFile("Accounts.txt");
            DisplayAccounts();
            ApplyInterest();
            DisplayAccounts();
            SaveFile("UpdatedAccounts.txt"); */

            /* ReadFile("Accounts.txt");
            SaveBinaryFile("Accounts.bin"); */

            LoadBinaryFile("Accounts.bin");
            DisplayAccounts();
        }
    }
}
