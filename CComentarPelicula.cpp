#include "CComentarPelicula.h"
#include "Sesion.h"
#include <stdexcept>

using namespace std;

CComentarPelicula::CComentarPelicula() {
    this->manejadorPelicula = ManejadorPelicula::getInstancia();
    this->manejadorUsuario = ManejadorUsuario::getInstancia();
    this->manejadorComentario = ManejadorComentario::getInstancia();
    this->peliculaSeleccionada = nullptr;
}

map<int, Comentario*>& CComentarPelicula::getComentarios() {
    return this->manejadorComentario->getComentarios();
}

bool CComentarPelicula::hayUsuarioLogueado() {
    return Sesion::getInstancia()->getUsuario() != nullptr;
}

list<DtPelicula> CComentarPelicula::listarPeliculas() {
    return this->manejadorPelicula->listarPeliculas();
}

void CComentarPelicula::selectPeli(string titulo) {
    this->peliculaSeleccionada = this->manejadorPelicula->obtenerPelicula(titulo);
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No existe una película con ese título");
    }
}

void CComentarPelicula::comentar(string texto) {
    if (!this->hayUsuarioLogueado()) {
        throw invalid_argument("No hay usuario logueado");
    }
    
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No hay película seleccionada");
    }

    Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();
    Comentario* nuevoComentario = new Comentario(texto, usuarioActual, this->peliculaSeleccionada);
    this->manejadorComentario->agregarComentario(nuevoComentario);
}

Comentario* CComentarPelicula::obtenerComentario(int id) {
    return this->manejadorComentario->obtenerComentario(id);
}

void CComentarPelicula::responder(int id, string texto) {
    if (!this->hayUsuarioLogueado()) {
        throw invalid_argument("No hay usuario logueado");
    }
    
    if (this->peliculaSeleccionada == nullptr) {
        throw invalid_argument("No hay película seleccionada");
    }

    Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();
    Comentario* comentarioOriginal = this->obtenerComentario(id);
    if (comentarioOriginal == nullptr) {
        throw invalid_argument("No existe un comentario con ese ID");
    }

    Comentario* respuesta = new Comentario(texto, usuarioActual, this->peliculaSeleccionada);
    this->manejadorComentario->agregarComentario(respuesta);
    comentarioOriginal->agregarRespuesta(respuesta);
}

list<DtComentario*> CComentarPelicula::obtenerComentariosPeliculaSeleccionada() {
    list<DtComentario*> comentariosPelicula;
    
    if (this->peliculaSeleccionada == nullptr) {
        return comentariosPelicula; // Lista vacía
    }
    
    // EL CONTROLADOR hace el filtrado, no el manejador
    map<int, Comentario*>& todosLosComentarios = this->manejadorComentario->getComentarios();
    for (map<int, Comentario*>::iterator it = todosLosComentarios.begin(); it != todosLosComentarios.end(); ++it) {
        if (it->second->getPelicula()->getTitulo() == this->peliculaSeleccionada->getTitulo() && 
            it->second->getComentarioPadre() == nullptr) {
            DtComentario* dtComentario = convertirComentarioADt(it->second);
            comentariosPelicula.push_back(dtComentario);
        }
    }
    
    return comentariosPelicula;
}

// Función auxiliar para convertir Comentario a DtComentario con respuestas
DtComentario* CComentarPelicula::convertirComentarioADt(Comentario* comentario) {
    if (comentario == nullptr) return nullptr;
    
    DtComentario* dtComentario = new DtComentario(comentario->getAutor()->getNickName(), comentario->getTexto());
    
    list<Comentario*> respuestas = comentario->getRespuestas();
    for (list<Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it) {
        dtComentario->agregarRespuesta(convertirComentarioADt(*it));
    }
    
    return dtComentario;
}

vector<int> CComentarPelicula::obtenerIdsComentariosPeliculaSeleccionada() {
    vector<int> idsComentarios;
    
    if (this->peliculaSeleccionada == nullptr) {
        return idsComentarios; // Vector vacío
    }
    
    // Obtener IDs en el mismo orden que obtenerComentariosPeliculaSeleccionada
    map<int, Comentario*>& todosLosComentarios = this->manejadorComentario->getComentarios();
    for (map<int, Comentario*>::iterator it = todosLosComentarios.begin(); it != todosLosComentarios.end(); ++it) {
        if (it->second->getPelicula()->getTitulo() == this->peliculaSeleccionada->getTitulo() && 
            it->second->getComentarioPadre() == nullptr) {
            idsComentarios.push_back(it->second->getId());
        }
    }
    
    return idsComentarios;
}

CComentarPelicula::~CComentarPelicula() {
    // No liberamos los manejadores porque son singletons
}