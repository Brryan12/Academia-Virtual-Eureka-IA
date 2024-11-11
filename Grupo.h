#pragma once
#include "Profesor.h"
#include "Horario.h"
#include "Curso.h"
#include "Lista.h"
#include "Estudiante.h"
#include "Constantes.h"
class Grupo
{
private:

	/// @brief Periodo en el que se imparte el grupo
	std::string periodo;

	/// @brief Curso que se imparte en el grupo
	Curso* curso;

	/// @brief Identificador del grupo
	std::string IdGrupo;

	/// @brief Cupo fijo de estudiantes por grupo
	const int cupo=30;

	/// @brief Cantidad de estudiantes inscritos en el grupo
	int cantidadEstudiantes;

	/// @brief Horario en el que se imparte el grupo
	Horario *horario;

	/// @brief Profesor que imparte el grupo
	Profesor* profesor;

	/// @brief Lista de estudiantes inscritos en el grupo
	Lista<Estudiante>* estudiantes;
public:

	/// @brief Constructor por defecto
	Grupo();

	/// @brief Constructor con parametros
	/// @param periodo Periodo en el que se imparte el grupo
	/// @param curso Curso que se imparte en el grupo
	/// @param IdGrupo Identificador del grupo
	/// @param horario Horario en el que se imparte el grupo
	Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario);

	/// @brief Constructor con parametros
	/// @param periodo Periodo en el que se imparte el grupo
	/// @param curso Curso que se imparte en el grupo
	/// @param IdGrupo Identificador del grupo
	/// @param horario Horario en el que se imparte el grupo
	/// @param profesor Profesor que imparte el grupo
	Grupo(std::string periodo, Curso* curso, std::string IdGrupo, Horario* horario, Profesor* profesor);

	/// @brief Destructor
	virtual ~Grupo();

	/// @brief Obtiene el cupo fijo de estudiantes por grupo
	/// @return Cupo fijo de estudiantes por grupo
	int getCupo() const;

	/// @brief Obtiene el periodo en el que se imparte el grupo
	/// @return Periodo en el que se imparte el grupo
	std::string getPeriodo() const;

	/// @brief Obtiene el identificador del grupo
	/// @return Identificador del grupo
	std::string getId() const;

	/// @brief Obtiene la cantidad de estudiantes inscritos en el grupo
	/// @return Cantidad de estudiantes inscritos en el grupo
	int getCantidadEstudiantes() const;

	/// @brief Obtiene el curso que se imparte en el grupo
	/// @return Curso que se imparte en el grupo
	Curso* getCurso() const;

	/// @brief Obtiene el horario en el que se imparte el grupo
	/// @return Horario en el que se imparte el grupo
	Horario* getHorario() const;

	/// @brief Obtiene el profesor que imparte el grupo
	/// @return Profesor que imparte el grupo
	Profesor* getProfesor() const;

	/// @brief setea el periodo en el que se imparte el grupo
	/// @param periodo Periodo en el que se imparte el grupo
	void setPeriodo(std::string periodo);

	/// @brief setea el identificador del grupo
	/// @param IdGrupo Identificador del grupo
	void setIdGrupo(std::string IdGrupo);

	/// @brief setea la cantidad de estudiantes inscritos en el grupo
	/// @param cantidadEstudiantes Cantidad de estudiantes inscritos en el grupo
	void setCantidadEstudiantes(int cantidadEstudiantes);

	/// @brief setea el curso que se imparte en el grupo
	/// @param curso Curso que se imparte en el grupo
	void setCurso(Curso* curso);

	/// @brief setea el horario en el que se imparte el grupo
	/// @param horario Horario en el que se imparte el grupo
	void setHorario(Horario* horario);

	/// @brief setea el profesor que imparte el grupo
	/// @param profesor Profesor que imparte el grupo
	/// @return True si se seteo correctamente, false en caso contrario
	bool setProfesor(Profesor* profesor);

	/// @brief Convierte la informacion del grupo en un string
	std::string toString() const;

	/// @brief Inserta un estudiante en la lista de estudiantes del grupo
	/// @param estudiante Estudiante a insertar
	/// @return True si se inserto correctamente, false en caso contrario
	bool insertarEstudiante(Estudiante* estudiante);

	/// @brief Elimina un estudiante de la lista de estudiantes del grupo
	/// @param id Identificador del estudiante a eliminar
	/// @return True si se elimino correctamente, false en caso contrario
	bool eliminarEstudiante(std::string id);

	/// @brief Imprime la informacion de los grupos seperados por periodo
	/// @param lista Lista de Grupos
	/// @return Informacion de los grupos separados por periodo
	static std::string toStringPeriodos(Lista<Grupo>* lista);

	/// @brief Imprime la informacion basica de los grupos
	/// @param lista Lista de Grupos
	/// @return Informacion basica de los grupos
	static std::string toStringBasico(Lista<Grupo>* lista);

	/// @brief Imprime la informacion de los grupos sin profesor
	/// @param lista Lista de Grupos
	/// @return Informacion de los grupos sin profesor
	static std::string GruposSinProfesor(Lista<Grupo>* lista);

	/// @brief Imprime la informacion de los grupos con profesor
	/// @param lista Lista de Grupos
	/// @return Informacion de los grupos con profesor
	static std::string GruposConProfesor(Lista<Grupo>* lista);

	/// @brief Guarda la informacion del grupo en un archivo
	/// @param salida Flujo de salida donde se guardara la informacion
	void guardar(std::ostream& salida) const;

	/// @brief Lee la informacion del grupo de un archivo
	/// @param entrada Flujo de entrada de donde se leera la informacion
	/// @return Grupo leido
	static Grupo* leer(std::istream& entrada);
};

