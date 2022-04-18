from ast import Add
import pandas as pd
import random

from faker import Faker
faker = Faker('en_US')

COUNT = 100000

def generate_names(count, type):

    item_list = []
    for i in range(count):
        if(type == 'ssn'):
            c_item = faker.ssn()
        elif(type == 'first_name'):
            c_item = faker.first_name()
        elif(type == 'last_name'):
            c_item = faker.last_name()
        elif (type == 'address'):
            c_item = faker.address()

        print(f'[{i}] : {c_item}')
        item_list.append(c_item)

    return item_list

def generate_data():

    global faker

    ssn_list = generate_names(COUNT, 'ssn')
    first_name_list = generate_names(COUNT, 'first_name')
    last_name_list = generate_names(COUNT, 'last_name')
    address_list = generate_names(COUNT, 'address')

    data = pd.DataFrame({
        'ssn' : ssn_list,
        'first_name' : first_name_list,
        'last_name' : last_name_list,
        'address' : address_list,
    })
    
    data['email'] = data['first_name'] + '.' + data['last_name'] + '@miraIncorporated.com'
    data['address'] = data['address'].str.replace('\n', ' ')

    return data

def startpy():
    
    data = generate_data()
    print(data)

    data.to_csv('./userData.csv')


if __name__ == '__main__':
    startpy()