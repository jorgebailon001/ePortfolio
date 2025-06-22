
import logging

def setup_logger():
    logging.basicConfig(
        filename='bank_app.log',
        filemode='a',
        format='%(asctime)s - %(levelname)s - %(message)s',
        level=logging.INFO
    )
    return logging.getLogger('BankLogger')