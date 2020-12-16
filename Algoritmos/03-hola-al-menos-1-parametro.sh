echo $1 #Capta el Primer parametro ingresado
if [ -n "$1" ]; then #Comprueba que este parametro exista
	echo Hola $1 #imprime el mensaje mas el parametro puesto
else #sino
	echo "No ingreso parametros" #Imprime no ingreso parametros
fi
