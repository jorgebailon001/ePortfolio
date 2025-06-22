
import unittest
from bank import BankManager

class TestBankManager(unittest.TestCase):

    def setUp(self):
        self.bank = BankManager()
        self.account = self.bank.open_account("Alice", "Smith", "30", "Savings", 500)

    def test_account_creation(self):
        self.assertEqual(self.account.first_name, "Alice")
        self.assertEqual(self.account.balance, 500)
        self.assertTrue(self.account.account_number >= 1000000)

    def test_find_existing_account(self):
        found = self.bank.find_account(self.account.account_number)
        self.assertEqual(found.last_name, "Smith")

    def test_find_nonexistent_account(self):
        with self.assertRaises(LookupError):
            self.bank.find_account(9999999)

    def test_display_accounts_output(self):
        # This just ensures no exceptions occur during display
        try:
            self.bank.display_accounts()
        except Exception as e:
            self.fail(f"display_accounts() raised an exception: {e}")

    def test_multiple_account_creation(self):
        acc2 = self.bank.open_account("Bob", "Jones", "22", "Checking", 1000)
        self.assertEqual(len(self.bank.accounts), 2)
        self.assertNotEqual(self.account.account_number, acc2.account_number)

if __name__ == "__main__":
    unittest.main()
