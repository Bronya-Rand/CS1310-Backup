using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleFileProg_1
{
    [Serializable]
    internal class Account
    {
        public string AccountNo { get; set; }
        public string HolderName { get; set; }
        public decimal Balance { get; set; }

        public Account(string accountNo, string holderName, decimal balance)
        {
            AccountNo = accountNo;
            HolderName = holderName;
            Balance = balance;
        }
    }
}
