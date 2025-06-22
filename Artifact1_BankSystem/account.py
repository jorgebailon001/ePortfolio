class Account:
    account_counter = 1000000 # static account number generator

    def __init__(self, first_name, last_name, age, account_type, deposit):
        self.account_number = Account.account_counter
        Account.account_counter += 1

        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.account_type = account_type
        self.balance = deposit

    def deposit(self, amount):
        if amount <= 0:
            raise ValueError("Deposit must be greater than zero.")
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            raise ValueError("Insufficient funds.")
        self.balance -= amount

    def __str__(self):
        return (f"Account Number: {self.account_number}\n"
                f"Name: {self.first_name} {self.last_name}\n"
                f"Age: {self.age}\n"
                f"Type: {self.account_type}\n"
                f"Balance: ${self.balance:.2f}")