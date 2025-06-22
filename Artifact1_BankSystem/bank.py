
from account import  Account

class BankManager:
    def __init__(self):
        self.accounts = []

    def open_account(self, first_name, last_name, age, account_type, deposit):
        new_account = Account(first_name, last_name, age, account_type, deposit)
        self.accounts.append(new_account)
        return new_account

    def find_account(self, account_number):
        for acc in self.accounts:
            if acc.account_number == account_number:
                return acc
        raise LookupError("Account not found.")

    def display_accounts(self):
        if not self.accounts:
            print("No accounts available.")
        else:
            for acc in self.accounts:
                print(acc)
                print("-" * 30)

