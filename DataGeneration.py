import pandas as pd
import random

from faker import Faker
faker = Faker()

COUNT = 100000

def generate_names(count, type):

    item_list = []
    for i in range(count):
        if(type == 'ssn'):
            c_item = faker.ssn()
        elif(type == 'name'):
            c_item = faker.name()

        print(f'[{i}] : {c_item}')
        item_list.append(c_item)

    return item_list

def generate_data():

    global faker

    ssn_list = generate_names(COUNT, 'ssn')
    user_name_list = generate_names(COUNT, 'name')

    data    = pd.DataFrame({
        'ssn' : ssn_list,
        'user_name' : user_name_list,
    })

    return data

def startpy():
    
    data = generate_data()
    print(data)

    data.to_csv('./userData.csv')


if __name__ == '__main__':
    startpy()