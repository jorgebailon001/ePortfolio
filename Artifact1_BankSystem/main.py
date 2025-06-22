

from bank import BankManager
from transaction import Deposit, Withdraw
from logger_config import setup_logger
logger = setup_logger()

def main():
    bank = BankManager()

    while True:
        print("\n--- MENU ---")
        print("1. Open Account")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Display Accounts")
        print("5. Exit")


        try:
            choice = int(input("Enter option: " ))
        except ValueError:
            print("Please enter a number." )
            continue

        try:
            if choice == 1:
                fn = input("First name: ")
                ln = input("Last name: ")
                age = input("Age: ")
                acc_type = input("Account type (Checking/Savings): ")
                deposit = float(input("Initial deposit: "))
                acc = bank.open_account(fn, ln, age, acc_type, deposit)
                print(f"Account created: {acc.account_number}")
                logger.info(f"Account opened: {acc.account_number}")

            elif choice == 2:
                acc_num = int(input("Account number: "))
                amount = float(input("Amount to deposit: "))
                acc = bank.find_account(acc_num)
                strategy = Deposit()
                strategy.execute(acc, amount)
                print("Deposit successful.")
                logger.info(f"Deposit: ${amount} to {acc.account_number}")

            elif choice == 3:
                acc_num = int(input("Account number: "))
                amount = float(input("Amount to withdraw: "))
                acc = bank.find_account(acc_num)
                strategy = Withdraw()
                strategy.execute(acc, amount)
                print("Withdrawal successful.")
                logger.info(f"Withdrawal: ${amount} from {acc.account_number}")

            elif choice == 4:
                bank.display_accounts()

            elif choice == 5:
                print("Goodbye!")
                break

            else:
                print("Invalid choice.")

        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
            main()