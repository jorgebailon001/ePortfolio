
class TransactionStrategy:
    def execute(self, account, amount):
        raise NotImplementedError("Subclasses must implement this method")

class Deposit(TransactionStrategy):
    def execute(self, account, amount):
        if amount <= 0:
            raise ValueError("Deposit must be greater than zero")
        account.balance += amount

class Withdraw(TransactionStrategy):
    def execute(self, account, amount):
        if amount > account.balance:
            raise ValueError("Insufficient funds.")
        account.balance -= amount