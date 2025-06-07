
Carrera: Técnico Universitario en Programación
Materia: Programación II
Tema: TP Final - Integrador



Integrantes de la cátedra
Kloster, Daniel - Profesor
Wenner, Maximiliano - Profesor
Lara Campos, Brian - Profesor
Simón, Angel  - Profesor
Malvicino, Maximiliano Raúl - Ayudante

TP Final Programación II. 2025 1C

Integrantes del Grupo N° 52 : 
Camila Milagros Ontivero → Legajo: 31729
Franco Damian Brandan → Legajo: 31782
Nicolas Lautaro Cragno → Legajo: 25109
Lucas Berlingeri → Legajo: 31718

Nombre: Empresa de Transporte

Tema: Sistema de gestión para asignación y control de los viajes que desarrolla una empresa de logística/transporte, con sus respectivos choferes y camiones.

Descripción: El sistema tiene como objetivo principal gestionar de manera eficiente los viajes de larga distancia de una empresa de transporte. El programa puede incorporar tanto choferes como camiones, con sus principales características y atributos. Se podrá asignar a cada chofer un camión, para luego generar y seguir en tiempo real una salida entre dos ciudades determinadas, transportando un tipo de carga en específico. A través de una interfaz basada en menús, el usuario puede administrar choferes, camiones, viajes, clientes y cargas, así como realizar consultas e informes detallados.


Archivos a utilizar:
1. Archivo de Camiones (camiones.dat):
  int _idCamion;		// Identificación única 
  char _patente[8];		// Patente
  char _marca[30];		// Nombre de marca
  char _modelo[30];		// Nombre de modelo
  int _anio;			// Año de fabricación	
  float _pesoCarga;		// Peso máximo soportado
  float _volumenCarga;		// Volumen máximo soportado
  float _kmMensuales[12];	// Kilómetros recorridos por mes en un año
  Fecha _ultimaVerificacion;	// Fecha en la que se le hizo la ultima verificación al camión
  bool _aptoCircular; 		// Luego de 1 año de pasada la fecha de la ultima verificación, si no se ha actualizado, se vence y este bool pasa a "false"
  bool _enViaje; 		// Si el camion se encuentra en viaje = true , si no = false
  bool _choferAsignado;  	// Si le asignamos un camión a un chofer, el estado pasa a "true"
  bool _estado;  		// Define si el registro esta activo o esta dado de baja

2. Archivo de Choferes (choferes.dat):
  int _id;			// Identificador unico
  bool _asignado; 		// Booleano para verificar si tiene o no tiene camion asignado
  Camiones _camionAsignado;   	// Objeto del camion que se le asigna al chofer
  int _dni;			// DNI de chofer		
  char _nombre[30];		// Nombre del chofer
  char _apellido[30];		// Apellido del chofer
  int _experiencia;		// Experiencia en años
  Fecha _vencimientoLicencia;	// Fecha de vencimiento de la licencia de conducir
  bool _aptoCircular;		// Si la licencia está vencida, este bool toma el valor de "false"
  bool _enViaje;		// Booleano para determinar si el chofer esta o no en viaje
  float _kmMensuales[12];	// Kilómetros recorridos por mes en un año
  bool _estado; 		// Define si el registro esta activo o esta dado de baja

3. Archivo de Viajes (viajes.dat):
  int _id;			// Identificador unico
  Choferes _chofer;		// Objeto chofer, que representa al chofer encargado de realizar el viaje
  Ciudades _ciudadOrigen;	// Objeto ciudad, que representa la ciudad de origen del viaje
  Ciudades _ciudadDestino;	// Objeto ciudad, que representa la ciudad de destino del viaje
  float _distancia;		// Distancia entre las ciudades
  struct tm _fechaSalida;	// Fecha de salida --> Representada en struct tm para luego hacer calculos con time(), para obtener tiempos estimados de viaje y tiempos restantes de finalizacion de viaje.
  struct tm _fechaLlegada;	// Fecha de llegada --> Representada en struct tm para luego hacer calculos con time(), para obtener tiempos estimados de viaje y tiempos restantes de finalizacion de viaje.
  char _tipoCarga[30];		// Tipo de carga transportada
  float _pesoTransportado;	// Peso transportado en el viaje
  float _volumenTransportado;	// Volumen transportado en el viaje
  bool _estado;			// Estado true = "viaje en curso" o false = "viaje finalizado"
  Clientes _cliente;		// Cliente al cual se le presta el servicio

4. Archivo de Ciudades (ciudades.dat) (Archivo precargado) :

5. Archivo de Usuarios (usuarios.dat):

6.Archivo de Clientes (clientes.dat):



Clases a desarrollar:

-Camiones → Atributos principales de los camiones, getters, setters y funciones de mostrar.

-CamionesArchivo → métodos para leer, buscar, agregar o modificar el archivo camiones.

-CamionesManager → Articulador, todo lo que se muestra relacionado a camiones pasa por  esta clase (altas, bajas, modificaciones, listados, etc).

-Choferes → Atributos principales de los choferes, getters, setters y funciones de mostrar.

-ChoferesArchivo → Métodos para leer, buscar, agregar o modificar el archivo choferes.

-ChoferesManager → Articulador, todo lo que se muestra relacionado a choferes pasa por  esta clase (altas, bajas, modificaciones, listados, etc)

-Viajes  → Atributos principales de los viajes, getters, setters y funciones de mostrar.

-ViajesArchivo → Métodos para leer, buscar, agregar o modificar el archivo Viajes.

-ViajesManager → Se podría decir que es la clase principal, el motor y la razón de ser del programa, esta clase va a estar conectada a casi la totalidad del resto de las clases. En ella se registran los viajes.

-Clientes → Atributos principales de los clientes, getters, setters y funciones de mostrar.

-ClientesManager → Articulador, todo lo que se muestra relacionado a Clientes pasa por  esta clase (altas, bajas, modificaciones, listados, etc)

-ClientesArchivo → Métodos para leer, buscar, agregar o modificar el archivo Clientes.

-menuPrincipal → Menú principal, de él se desprenden el resto de los menúes.

-menuCamiones → Menú para sección camiones.

-menuChoferes → Menú para sección choferes.

-menuViajes → Menú para sección Viajes.

-menuClientes → Menú para sección Clientes.

-Fecha → Clase para manejar diferentes fechas en el programa

-Ciudades → Clase utilizada para buscar y establecer la distancia entre dos ciudades. Basada en el archivo “Ciudades” que contiene una base de datos de una gran cantidad de localidades de Argentina con sus respectivas coordenadas geográficas.

-Carga → Clase utilizada para establecer diferentes tipos de cargas a transportar

-Usuarios → Se pretende darle seguridad al programa mediante usuarios, todavía no se encuentra creada. En un futuro, si es necesario, se podría separar en manager y archivo.

-UsuariosManager -> Articulador, todo lo que se muestra relacionado a usuarios pasa por  esta clase (altas, bajas, modificaciones, listados, etc)

-UsuariosArchivo -> métodos para leer, buscar, agregar o modificar el archivo usuarios.


Reportes/Listados:

Listado de camiones disponibles
Muestra todos los camiones activos del sistema, junto con sus datos principales: patente,   carga, marca y modelo.

Listado de camiones con verificación vencida
Muestra aquellos camiones a los cuales se les ha vencido la verificación técnica


Listado de kilómetros recorridos por camión
Muestra los kilómetros recorridos por mes, por cada camión.

Listado de choferes activos
Muestra los choferes que están en servicio, incluyendo nombre, DNI,  disponibilidad y horario de llegada 

Listado de kilómetros recorridos por chofer
Muestra los kilómetros recorridos por mes, por cada chofer.


Viajes realizados por un chofer
Permite seleccionar un chofer y visualizar todos los viajes que ha realizado, incluyendo origen, destino, fechas

Historial de viajes
Muestra todos los viajes realizados

Viajes Activos
Muestra aquellos viajes que se encuentran en transcurso

Clientes
Muestra los clientes, sus datos  y si tiene viajes realizados con la empresa 



