
import unittest
from account import Account
from transaction import Deposit, Withdraw

class TestTransactionStrategy(unittest.TestCase):

    def setUp(self):
        self.account = Account("Test", "User", "25", "Checking", 100)

    def test_deposit(self):
        Deposit().execute(self.account, 50)
        self.assertEqual(self.account.balance, 150)

    def test_withdraw(self):
        Withdraw().execute(self.account, 40)
        self.assertEqual(self.account.balance, 60)

    def test_withdraw_insufficient(self):
        with self.assertRaises(ValueError):
            Withdraw().execute(self.account, 200)

    def test_invalid_deposit(self):
        with self.assertRaises(ValueError):
            Deposit().execute(self.account, -50)

if __name__ == '__main__':
    unittest.main()
