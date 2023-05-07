import csv
from faker import Faker
from datetime import datetime, timedelta
import random

def generate_random_data(filename):
    fake = Faker()
    with open(filename, 'w', newline='') as csvfile:
        fieldnames = ['Nombre', 'Edad', 'Numero de cuenta', 'Sexo', 'Fecha de nacimiento']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for i in range(200):
            name = fake.name()
            age = random.randint(18, 65)
            account_number = random.randint(10000, 99999)
            gender = random.choice(['Masculino', 'Femenino'])
            birthdate = (datetime.now() - timedelta(days=random.randint(365*18, 365*65))).strftime('%Y-%m-%d')
            writer.writerow({'Nombre': name, 'Edad': age, 'Numero de cuenta': account_number, 'Sexo': gender, 'Fecha de nacimiento': birthdate})

def sort_csv_by_age(filename):
    with open(filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        records = list(reader)
    
    # Convertir edad de str a int
    for record in records:
        record['Edad'] = int(record['Edad'])
    
    # Ordenar registros por edad
    records.sort(key=lambda x: x['Edad'])
    
    # Escribir registros ordenados en un nuevo archivo CSV
    with open('sorted_' + filename, 'w', newline='') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=reader.fieldnames)
        writer.writeheader()
        writer.writerows(records)

# Ejemplo de uso
generate_random_data('datos.csv')
sort_csv_by_age('datos.csv')
