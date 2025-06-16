# REGLAS PARA IMPLEMENTACIÓN DE CASOS DE USO
## Proyecto Obligatorio 5 - Sistema de Cines

---

## 🎯 REGLAS UML ESTRICTAS - BASE FUNDAMENTAL

### **DEPENDENCIAS PERMITIDAS POR CLASE:**

#### **Controladores (C*):**
- **CAltaFuncion** puede ver: `ManejadorPelicula`, `ManejadorCine`, `ManejadorFuncion`, `Pelicula`, `Cine`, `Funcion`
- **CVerInformacionPelicula** puede ver: `ManejadorPelicula`, `ManejadorCine`, `Pelicula`, `Cine`
- ⚠️ **NOTA**: Agregar otros controladores según sus casos de uso específicos

#### **Entidades de Dominio:**
- **Pelicula** puede SOLAMENTE ver: `Cine`
- **Cine** puede SOLAMENTE ver: `Sala`  
- **Sala** puede SOLAMENTE ver: `Funcion`
- **Funcion** puede SOLAMENTE ver: `Pelicula`

#### **Manejadores (Singleton):**
- **ManejadorPelicula** puede SOLAMENTE ver: `Pelicula`
- **ManejadorCine** puede SOLAMENTE ver: `Cine`
- **ManejadorFuncion** puede SOLAMENTE ver: `Funcion`
- **ManejadorUsuario** puede SOLAMENTE ver: `Usuario`

### **❌ VIOLACIONES PROHIBIDAS:**
- **NINGÚN Manejador** puede ver a **otros Manejadores**
- **NO forward declarations** (`class ClassName;`) - **PROHIBIDO**
- **NO dependencias circulares**
- **NO saltar niveles** en la jerarquía UML

---

## 🏗️ PATRONES DE IMPLEMENTACIÓN

### **1. ESTRUCTURA DE ARCHIVOS OBLIGATORIA:**

**Para cada caso de uso `NombreCasoDeUso`:**

```
IC[NombreCasoDeUso].h     // Interfaz (métodos virtuales puros)
C[NombreCasoDeUso].h      // Header del controlador
C[NombreCasoDeUso].cpp    // Implementación del controlador
```

### **2. PATRÓN DE INCLUDES OBLIGATORIO:**

#### **En archivos .h:**
```cpp
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>    // SIEMPRE incluir
#include <string>      // Si usa string
#include <list>        // Si usa list
#include <vector>      // Si usa vector

#include "ICControlador.h"        // Su interfaz
#include "ManejadorX.h"           // Manejadores necesarios
#include "EntidadY.h"             // Entidades de dominio
#include "DtZ.h"                  // Data Types necesarios

using namespace std;

class CControlador : public ICControlador {
    // implementación
};
#endif
```

### **3. PATRÓN DE ATRIBUTOS EN CONTROLADORES:**

```cpp
class CControlador : public ICControlador {
private:
    // Atributos para "recordar" selecciones del usuario
    string seleccionUsuario1;
    int seleccionUsuario2;
    // NO punteros a objetos (usar IDs/nombres)
    
public:
    CControlador();
    // métodos de la interfaz
    ~CControlador();
};
```

---

## 🔄 FLUJOS DE CASOS DE USO

### **PATRÓN ESTÁNDAR:**

1. **Listar elementos** → Acceder a Manejador → Obtener colección → Crear Dt*
2. **Seleccionar elemento** → Recordar selección (string/int, NO punteros)
3. **Operaciones en cascada** → Usar selecciones previas
4. **Operación final** → Crear/modificar entidades → Agregar a Manejadores

### **EJEMPLO: CAltaFuncion**
```
1. listarPeliculas() → ManejadorPelicula → list<DtPelicula>
2. selectPeli(titulo) → Recordar titulo
3. listarCines() → Pelicula seleccionada → getCines() → list<DtCine>  
4. selectCine(idCine) → Recordar idCine
5. listarSalas() → Cine seleccionado → getDtSalas() → list<DtSala>
6. selectSala(idSala) → Recordar idSala
7. altaFuncion() → Crear Funcion → Agregar a ManejadorFuncion
```

---

## 📋 REGLAS DE DATA TYPES (Dt*)

### **CREACIÓN DE Dt*:**
- **Quién puede crear DtX**: Solo clases que pueden ver X
- **Contenido**: Solo información que la clase creadora puede acceder
- **Ejemplo**: `Cine` puede crear `DtSala` porque puede ver `Sala`

### **TRANSFERENCIA:**
- Los Dt* se usan para transferir información **sin violar UML**
- NO contienen punteros, solo valores primitivos
- Son **inmutables** una vez creados

---

## ⚠️ LIMITACIONES CONOCIDAS

### **Problema: Asignaciones Complejas**
Cuando un caso de uso requiere asignar **A** a **B**, pero el controlador no puede ver ambos:

**Ejemplo**: `Funcion` → `Sala`
- Controlador no puede ver `Sala`  
- `Cine` no puede ver `Funcion`
- `ManejadorFuncion` no puede ver `ManejadorCine`

**Solución**: 
1. El controlador crea la entidad
2. La asignación se hace **externamente** por quien use la interfaz
3. Documentar la limitación claramente

---

## 🛠️ CHECKLIST DE IMPLEMENTACIÓN

### **Antes de codificar:**
- [ ] ✅ Revisar diagramas UML del caso de uso
- [ ] ✅ Identificar dependencias permitidas
- [ ] ✅ Planificar flujo respetando jerarquías
- [ ] ✅ Identificar limitaciones UML

### **Durante la implementación:**
- [ ] ✅ NO usar forward declarations
- [ ] ✅ Incluir TODAS las dependencias explícitamente
- [ ] ✅ Usar patrones de `foreach` para iteraciones
- [ ] ✅ Crear Dt* solo desde clases que pueden ver la entidad

### **Verificación final:**
- [ ] ✅ ¿Se respetan TODAS las dependencias UML?
- [ ] ✅ ¿No hay forward declarations?
- [ ] ✅ ¿El flujo sigue la arquitectura correcta?
- [ ] ✅ ¿Las limitaciones están documentadas?

---

## 📝 CASOS DE USO ESPECÍFICOS

### **🔐 INICIAR SESIÓN**
**Actores:** Usuario  
**Sinopsis:** El caso de uso comienza cuando un usuario, que no tiene una sesión iniciada, desea iniciar sesión en el sistema ingresando su nickname. El sistema solicita su contraseña y si es correcta se asigna la sesión al usuario. Si se ingresa una contraseña incorrecta, el usuario podrá volver a ingresar otra o cancelar el caso de uso.

**Dependencias UML:**
- **CIniciarSesion** puede ver: `ManejadorUsuario`, `Sesion`, `Usuario`
- **Flujo:** nickname → buscar usuario → validar contraseña → crear sesión

---

### **🚪 CERRAR SESIÓN**
**Actores:** Usuario  
**Sinopsis:** El caso de uso comienza cuando un usuario que tiene sesión iniciada desea finalizarla. El usuario selecciona "Cerrar Sesión" y el sistema elimina la sesión activa, redirigiendo a la pantalla principal o de login.

**Dependencias UML:**
- **CCerrarSesion** puede ver: `Sesion`
- **Flujo:** verificar sesión activa → eliminar sesión

---

### **👤 ALTA USUARIO**
**Actores:** Usuario Administrador  
**Sinopsis:** El caso de uso comienza cuando un invitado desea registrarse en el sistema para crear un nuevo usuario. El sistema solicita nickname, contraseña y URL de foto de perfil (opcional). Si el nickname está disponible, se crea el usuario y se confirma el alta. Si no, se informa el error y se permite reintentar o cancelar.

**Dependencias UML:**
- **CAltaUsuario** puede ver: `ManejadorUsuario`, `Usuario`
- **Flujo:** nickname + contraseña + foto → validar disponibilidad → crear usuario

---

### **🎬 ALTA PELÍCULA**
**Actores:** Usuario Administrador  
**Sinopsis:** El caso de uso comienza cuando un administrador, que previamente ha iniciado sesión, desea agregar una nueva película. El sistema solicita ingresar título, sinopsis y URL del póster. Si el título es único, se registra la película; si no, se informa el error y se permite reintentar o cancelar.

**Dependencias UML:**
- **CAltaPelicula** puede ver: `ManejadorPelicula`, `Pelicula`, `Sesion`
- **Flujo:** verificar admin → título + sinopsis + poster → validar unicidad → crear película

---

### **🏢 ALTA CINE**
**Actores:** Usuario Administrador  
**Sinopsis:** El caso de uso comienza cuando un administrador, que previamente ha iniciado sesión, desea agregar cines en el sistema. Para cada cine, en primer lugar, el sistema le permite ingresar la dirección del cine. Luego, le permite ingresar una a una las salas del cine. Para cada sala, le solicita que ingrese su capacidad. Finalmente, el sistema le solicita que confirme o cancele si desea agregar el cine. Si confirma, el sistema da de alta al cine y sus salas generando internamente (sin solicitarle al administrador) el número del cine y los números de las salas. Si cancela continúa con el siguiente cine si así lo desea o termina el caso de uso.

**Dependencias UML:**
- **CAltaCine** puede ver: `ManejadorCine`, `Cine`, `Sala`, `Sesion`
- **Flujo:** verificar admin → dirección → agregar salas (capacidad c/u) → confirmar → crear cine + salas con IDs autogenerados

---

## 📝 CASOS DE USO PENDIENTES

**TODO**: Expandir este documento con reglas específicas para:

- [x] **IniciarSesion** ✅
- [x] **CerrarSesion** ✅  
- [x] **AltaUsuario** ✅
- [x] **AltaPelicula** ✅
- [x] **AltaCine** ✅
- [ ] **VerInformacionPelicula**
- [ ] **CrearReserva**
- [ ] **PuntuarPelicula**
- [ ] **ComentarPelicula**
- [ ] **EliminarPelicula**
- [ ] Otros...

---

**REGLA DE ORO**: Cuando hay duda sobre dependencias UML, **PREGUNTAR** antes de implementar. Es mejor consultar que violar la arquitectura. 