from ast import Add
import numpy as np
import random
import pandas as pd

from password_generator import PasswordGenerator
from faker import Faker

faker = Faker('en_US')

pw = PasswordGenerator()
pw.maxlen = 8
pw.excludeschars = ",/"

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
        elif(type == 'password'):
            c_item = pw.generate()

        item_list.append(c_item)

    return item_list

def generate_data():

    global faker

    ssn_list = generate_names(COUNT, 'ssn')
    first_name_list = generate_names(COUNT, 'first_name')
    last_name_list = generate_names(COUNT, 'last_name')
    address_list = generate_names(COUNT, 'address')
    password_list = generate_names(COUNT, 'password')

    data = pd.DataFrame({
        'ssn' : ssn_list,
        'first_name' : first_name_list,
        'last_name' : last_name_list,        
        'password' : password_list,
        'address' : address_list,
    })
    data['rand'] = np.random.randint(1, 1000, data.shape[0])
    data = data.astype({'rand': str})
    data['username'] = data['first_name'] + '.' + data['last_name'] + data['rand']
    data['address'] = data['address'].str.replace('\n', ' ')
    data['address'] = data['address'].str.replace(',', '')
    data['email'] = data['username'] + '@miraIncorporated.com'
    data = data.drop('rand', axis=1)

    data = data[['ssn', 'first_name', 'last_name', 'address','email', 'username', 'password']]
    return data

def startpy():
    
    data = generate_data()
    print(data.head())

    # Eliminate SSN Duplicates
    noSSNDups = False
    while(noSSNDups == False):
        data['ssnDuplicates'] = data.duplicated(subset =['ssn'])
        data = data.astype({"ssnDuplicates":bool})
        print(data['ssnDuplicates'].sum())
        if(data['ssnDuplicates'].sum() == 0):
            noSSNDups = True
        else:
            index = data.index
            condition = data['ssnDuplicates'] == True
            duplicateIndex = index[condition]
            indexLst = duplicateIndex.tolist()
            for ind in indexLst:
                data.at[int(ind), 'ssn'] = faker.ssn()

    data = data.drop('ssnDuplicates', axis=1)


    # Eliminate Username Duplicates
    noUserDups = False
    while(noUserDups == False):
        data['userDuplicates'] = data.duplicated(subset =['username'])
        data = data.astype({"userDuplicates":bool})
        print(data['userDuplicates'].sum())
        if(data['userDuplicates'].sum() == 0):
            noUserDups = True
        else:
            index = data.index
            condition = data['userDuplicates'] == True
            duplicateIndex = index[condition]
            indexLst = duplicateIndex.tolist()
            for ind in indexLst:
                newUser = data.at[int(ind), 'first_name'] + data.at[int(ind), 'last_name'] + str(np.random.randint(1, 1000, data.shape[0]))
                data.at[int(ind), 'username'] = newUser

    data.to_csv('./EmployeeData.csv')

    admin = data.loc[0:9, ['username', 'password']]
    print(admin.head())

    admin.to_csv('./AdminData.csv')


if __name__ == '__main__':
    startpy()