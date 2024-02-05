

def pedir_tipo():
  tipo_combustible = int(input("Que tipo de combustible se va a comprar [1] SUPER [2] ECO [3] DIESEL: "))
  return tipo_combustible

def pedir_cantidad(tipo_combustible):
  global super_gal_acum, eco_gal_acum, diesel_gal_acum
  galones = 0
  if tipo_combustible == 1:
    galones = float(input("Cuantos galones de SUPER compro: "))
    super_gal_acum += galones
  elif tipo_combustible == 2:
    galones = float(input("Cuantos galones de ECO compro: "))
    eco_gal_acum += galones
  elif tipo_combustible == 3:
    galones = float(input("Cuantos galones de DIESEL compro: "))
    diesel_gal_acum += galones
  return galones

def operaciones(tipo_combustible, cant_combustible):
  global super_usd_acum, eco_usd_acum, diesel_usd_acum, super_precio, eco_precio, diesel_precio
  if tipo_combustible == 1:
    if cant_combustible > 50:
      super_usd_acum += super_precio * cant_combustible * .9
    else:
      super_usd_acum += super_precio * cant_combustible
  elif tipo_combustible == 2:
    if cant_combustible > 25:
      eco_usd_acum += eco_precio * cant_combustible * .95
    else:
      eco_usd_acum += eco_precio * cant_combustible
  elif tipo_combustible == 3:
    if cant_combustible > 35:
      diesel_usd_acum += diesel_precio * cant_combustible * .93
    else:
      diesel_usd_acum += diesel_precio * cant_combustible

def mostrar_resultados():
  global super_usd_acum, eco_usd_acum, diesel_usd_acum, super_precio, eco_precio, diesel_precio
  print(f"\nHay {super_gal_acum} galones de SUPER.\nHay {eco_gal_acum} galones de ECO.\nHay {diesel_gal_acum} galones de DIESEL.\nHay {super_usd_acum} USD de SUPER.\nHay {eco_usd_acum} USD de ECO.\nHay {diesel_usd_acum} USD de DIESEL.")

def repetir_programa():
  global repeticion
  repeticion = int(input("Desea ingresar otra venta [1] Si [2] No: "))

super_precio, eco_precio, diesel_precio = 4.2, 1.85, 2.4
super_usd_acum = eco_usd_acum = diesel_usd_acum = 0
super_gal_acum = eco_gal_acum = diesel_gal_acum = 0
repeticion = 1

while (repeticion == 1):
  tipo = pedir_tipo()
  cantidad = pedir_cantidad(tipo)
  operaciones(tipo, cantidad)
  repetir_programa() 

mostrar_resultados()



numero = int(input("Ingrese un número entero positivo: "))

while numero <= 0:
    print("El número ingresado no es positivo")   
    numero = int(input("Ingrese un número entero positivo: "))

impares = []

for i in range(1, numero+1):
    if i % 2 != 0:
        impares.append(str(i))

print(", ".join(impares))