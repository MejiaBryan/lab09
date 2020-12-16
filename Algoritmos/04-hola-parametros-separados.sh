if [ $# -le 0 ]; then #Verifica la cantidad de parametros
	echo "Introducir mas de 1 parametro" #Si hay menos de 1 avisa
	exit 1 #termina el script
fi
msg="Hola," #crea un mensaje predeterminado
a=1 # verificador
while [ -n "$1" ]; do #bucle para separar por comas

	if [ $a -eq 1 ]; then #verificador en 1
		msg="$msg $1" #concatena msg predeterminado + parametro
		a=0 #vuelve al verificador 0
	else #sino
		msg="$msg, $1" #concatena con coma para imprimir
	fi
	shift
done
echo $msg"!" #imprime lo que este en el parametro msg
