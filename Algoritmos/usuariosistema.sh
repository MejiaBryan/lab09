function ayuda() { #Mensaje de ayuda
cat << ayuda_des
	Si algun usuario coincide en el sistema dice SI
	Si ningun usuario coincide en el sistema dice NO
	1 Si el numero de parametros es diferente de 1
ayuda_des
}
if [ $# -ne 1 ]; then #Comprobando la cantidad de parametros
	echo "Parametros son de uno" #mensaje de aviso
	ayuda #llamada a la funcion ayuda
	exit 1
fi
usuario='grep | -E ^$1: /etc/passwd' #busca usuarios registrados en el sistema
if [ -z "$usuario" ]; then #si existe el usuario en la variable
	echo "NO" #no si no existe
else
	echo "SI" #si existe si
fi
