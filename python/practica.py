"""
Funciones definidas por el usuario
"""
"""
# Simple

def greet():
    print("Hola, Python!")

greet()

# Con retorno

def return_greet():
    return "Hola, Python!"

greet = return_greet()
print(greet)

print(return_greet())

# Con argumentos

def arg_greet(name):
    print(f"Hola, {name}!")

arg_greet("Felipe")
"""

print("Programa para calcular el IVA")

valor = float(input("Caul es el valor de la compra: "))

def calculo_iva(valor):
    iva = valor * .12
    total = valor + iva
    print(f"Precio antes de IVA: {valor} USD\nValor del IVA: {iva} USD\nTotal: {total} USD")

calculo_iva(valor)