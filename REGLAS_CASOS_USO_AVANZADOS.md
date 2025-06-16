# REGLAS PARA CASOS DE USO AVANZADOS
## Proyecto Obligatorio 5 - Sistema de Cines

---

## 🎯 CASOS DE USO COMPLEJOS - ANÁLISIS DETALLADO

### **🎬 ALTA FUNCIÓN (VERSIÓN DETALLADA)**
**Actores:** Usuario Administrador  
**Sinopsis:** El caso de uso comienza cuando un administrador, que previamente ha iniciado sesión, desea dar de alta una función. Para ello el sistema lista las películas existentes y el usuario elige una. A continuación el sistema lista los cines y el usuario debe seleccionar uno. Luego el sistema lista las salas del cine elegido indicando la cantidad de asientos que poseen y cuando están ocupadas. Una vez seleccionada la sala el usuario ingresa la fecha y hora de la función y el sistema la da de alta. Esto se repite mientras el usuario quiera seguir agregando funciones para esa película.

**Dependencias UML:**
- **CAltaFuncion** puede ver: `ManejadorPelicula`, `ManejadorCine`, `ManejadorFuncion`, `Pelicula`, `Cine`, `Funcion`, `Sesion`
- **Flujo:** verificar admin → listar películas → seleccionar película → listar cines → seleccionar cine → listar salas (con ocupación) → seleccionar sala → ingresar fecha/hora → crear función → repetir si desea

**Consideraciones Especiales:**
- ✅ Mostrar ocupación de salas requiere que `Cine->getDtSalas()` incluya información de funciones
- ✅ Loop para agregar múltiples funciones para la misma película
- ⚠️ **LIMITACIÓN UML**: Asignación función→sala debe resolverse externamente

---

### **🎫 CREAR RESERVA**
**Actores:** Usuario  
**Sinopsis:** El caso de uso comienza cuando un usuario, que previamente ha iniciado sesión, desea reservar asientos para ver una película. El sistema lista los títulos de todas las películas registradas, y el usuario selecciona el título que desee, o puede cancelar. En caso de seleccionar una película, el sistema muestra su póster, y su sinopsis. El usuario puede elegir si finalizar el caso de uso, o ver información adicional de dicha película. Si desea ver la información adicional, se listan los cines en los que pasan esa película. Se puede optar por finalizar, o seleccionar un cine. Si se selecciona un cine, se listan para esa película y ese cine las funciones existentes posteriores a la fecha y hora actual. El usuario puede repetir este proceso para otra película, si lo desea. Una vez elegida la película, selecciona la función que desea ver, y el sistema le solicita la cantidad de asientos que desea reservar. Una vez ingresada la cantidad, el sistema le pide que ingrese el modo de pago (crédito o débito). En caso de débito ingresa nombre del banco; en crédito, nombre de la financiera, y se indica si tiene descuento. Finalmente, el usuario ve el precio total y puede confirmar o cancelar. Si confirma se crea la reserva.

**Dependencias UML:**
- **CCrearReserva** puede ver: `ManejadorPelicula`, `ManejadorCine`, `ManejadorFuncion`, `Pelicula`, `Cine`, `Funcion`, `Reserva`, `ReservaCredito`, `ReservaDebito`, `Credito`, `Debito`, `Sesion`

**Flujo Complejo:**
1. verificar usuario logueado → listar películas
2. seleccionar película → mostrar póster/sinopsis
3. **OPCIONAL**: ver info adicional → listar cines de la película
4. **OPCIONAL**: seleccionar cine → listar funciones futuras
5. seleccionar función → ingresar cantidad asientos
6. elegir modo pago:
   - **Débito**: nombre banco → crear ReservaDebito
   - **Crédito**: financiera + descuento → crear ReservaCredito
7. calcular precio total → confirmar → crear reserva

**Consideraciones Especiales:**
- ✅ Flujo no lineal con múltiples opciones de navegación
- ✅ Filtrado de funciones por fecha/hora actual
- ✅ Polimorfismo en tipos de pago (Credito/Debito)
- ✅ Cálculo de precios según tipo de pago y descuentos

---

### **📊 VER RESERVAS DE PELÍCULA**
**Actores:** Usuario Administrador  
**Sinopsis:** El caso de uso comienza cuando un usuario desea consultar reservas de películas. El sistema lista los títulos y el usuario selecciona uno. Se muestran funciones y reservas asociadas, incluyendo entradas, costo y pago.

**Dependencias UML:**
- **CVerReservasPelicula** puede ver: `ManejadorPelicula`, `Pelicula`, `Cine`, `Funcion`, `Reserva`, `Sesion`

**Flujo:**
- verificar admin → listar películas → seleccionar película → mostrar funciones y reservas (entradas, costo, pago)

**Consideraciones Especiales:**
- ✅ Requiere navegar: Pelicula → Cines → Salas → Funciones → Reservas
- ✅ Mostrar información financiera de las reservas
- ⚠️ **LIMITACIÓN UML**: El controlador no puede ver Sala directamente

---

### **🗑️ ELIMINAR PELÍCULA**
**Actores:** Usuario Administrador  
**Sinopsis:** Comienza cuando un administrador desea eliminar una película. El sistema lista títulos, el administrador selecciona uno, confirma o cancela. Al confirmar se eliminan película, funciones y reservas asociadas.

**Dependencias UML:**
- **CEliminarPelicula** puede ver: `ManejadorPelicula`, `ManejadorFuncion`, `Pelicula`, `Funcion`, `Sesion`

**Flujo:**
- verificar admin → listar películas → seleccionar película → confirmar → eliminar película + funciones + reservas en cascada

**Consideraciones Especiales:**
- ✅ Eliminación en cascada (película → funciones → reservas)
- ⚠️ **LIMITACIÓN UML**: El controlador no puede acceder directamente a Reserva
- ✅ Operación destructiva requiere confirmación explícita

---

### **⭐ PUNTUAR PELÍCULA**
**Actores:** Usuario  
**Sinopsis:** El usuario puntuará una película. El sistema lista películas, el usuario elige una, ve puntaje previo si existe, ingresa nuevo puntaje o finaliza.

**Dependencias UML:**
- **CPuntuarPelicula** puede ver: `ManejadorPelicula`, `Pelicula`, `Puntaje`, `Usuario`, `Sesion`

**Flujo:**
- verificar usuario → listar películas → seleccionar película → mostrar puntaje previo → ingresar nuevo puntaje → actualizar promedio

**Consideraciones Especiales:**
- ✅ Verificar si usuario ya puntuó la película
- ✅ Actualizar puntaje promedio de la película
- ✅ Permitir modificar puntaje existente

---

### **💬 COMENTAR PELÍCULA**
**Actores:** Usuario  
**Sinopsis:** El usuario comenta una película. El sistema lista películas, muestra comentarios, permite crear nuevos o responder existentes mientras desee.

**Dependencias UML:**
- **CComentarPelicula** puede ver: `ManejadorPelicula`, `Pelicula`, `Comentario`, `Usuario`, `Sesion`

**Flujo:**
- verificar usuario → listar películas → seleccionar película → mostrar comentarios → crear nuevo comentario O responder existente → repetir si desea

**Consideraciones Especiales:**
- ✅ Estructura jerárquica de comentarios (comentario → respuestas)
- ✅ Loop para múltiples comentarios/respuestas
- ✅ Mostrar threads de conversación

---

### **📖 VER INFORMACIÓN DE PELÍCULA**
**Actores:** Usuario, Usuario Administrador  
**Sinopsis:** Lista títulos, usuario elige película, muestra póster y sinopsis, permite consultar cines y funciones posteriores a fecha actual.

**Dependencias UML:**
- **CVerInformacionPelicula** puede ver: `ManejadorPelicula`, `ManejadorCine`, `Pelicula`, `Cine`, `Funcion`

**Flujo:**
- listar películas → seleccionar película → mostrar póster/sinopsis → **OPCIONAL**: consultar cines → **OPCIONAL**: consultar funciones futuras

**Consideraciones Especiales:**
- ✅ Información básica vs. información detallada
- ✅ Filtrado de funciones por fecha actual
- ✅ Accesible para todos los tipos de usuario

---

### **📝 VER COMENTARIOS Y PUNTAJES DE PELÍCULA**
**Actores:** Usuario, Usuario Administrador  
**Sinopsis:** Usuario selecciona película, el sistema muestra puntajes promedio, comentarios y respuestas en formato jerárquico.

**Dependencias UML:**
- **CVerComentariosPuntajes** puede ver: `ManejadorPelicula`, `Pelicula`, `Comentario`, `Puntaje`, `Usuario`

**Flujo:**
- listar películas → seleccionar película → mostrar puntaje promedio → mostrar comentarios jerárquicos → mostrar respuestas

**Consideraciones Especiales:**
- ✅ Formato jerárquico de comentarios
- ✅ Cálculo y display de puntajes promedio
- ✅ Solo lectura (no modificación)

---

## 🏗️ PATRONES AVANZADOS IDENTIFICADOS

### **📊 PATRÓN DE NAVEGACIÓN NO LINEAL:**
```
CCrearReserva: Películas → [Información] → [Cines] → [Funciones] → Reserva
```
- Múltiples puntos de salida opcionales
- Estado del controlador más complejo
- Navegación hacia atrás permitida

### **🔄 PATRÓN DE OPERACIONES REPETITIVAS:**
```
CAltaFuncion: Película → [mientras desee: Cine → Sala → Función]
CComentarPelicula: Película → [mientras desee: Comentar/Responder]
```

### **🗑️ PATRÓN DE ELIMINACIÓN EN CASCADA:**
```
CEliminarPelicula: Película → Funciones → Reservas (eliminación completa)
```

### **👥 PATRÓN DE ACCESO MULTINIVEL:**
```
Público: Ver información básica
Usuario: Ver + Comentar + Puntuar + Reservar  
Admin: Todo + Gestión + Reportes
```

---

## ⚠️ LIMITACIONES UML CRÍTICAS IDENTIFICADAS

### **🚨 PROBLEMA 1: Acceso a Reservas**
- **CVerReservasPelicula** necesita ver Reservas
- **CEliminarPelicula** necesita eliminar Reservas
- **Reserva** no está en las dependencias permitidas para estos controladores

**Solución:** Agregar métodos en Manejadores o extender dependencias UML

### **🚨 PROBLEMA 2: Navegación Sala → Función**
- Múltiples controladores necesitan funciones de salas específicas
- Violación directa del acceso Controlador → Sala

**Solución:** Usar Cine como intermediario con métodos específicos

### **🚨 PROBLEMA 3: Información Financiera**
- **CCrearReserva** necesita calcular precios y manejar pagos
- **CVerReservasPelicula** necesita mostrar información de pago
- Requiere acceso a clases de pago (Credito/Debito)

**Solución:** Verificar dependencias UML para clases de pago

---

## 🛠️ RECOMENDACIONES DE IMPLEMENTACIÓN

### **ORDEN SUGERIDO:**
1. **CVerInformacionPelicula** (simple, ya parcialmente implementado)
2. **CPuntuarPelicula** (entidades simples)
3. **CComentarPelicula** (similar a puntuar)
4. **CVerComentariosPuntajes** (solo lectura)
5. **CCrearReserva** (complejo, requiere pagos)
6. **CVerReservasPelicula** (requiere acceso a reservas)
7. **CEliminarPelicula** (operación destructiva)

### **VERIFICACIONES PREVIAS:**
- [ ] ✅ Confirmar dependencias UML para clases Reserva, Credito, Debito
- [ ] ✅ Verificar métodos disponibles en Manejadores
- [ ] ✅ Identificar Data Types faltantes (DtReserva, DtPago, etc.)
- [ ] ✅ Planificar manejo de fechas/horas actuales
- [ ] ✅ Diseñar estructura jerárquica de comentarios

---

**REGLA DE ORO AVANZADA**: En casos de uso complejos, **dividir en sub-operaciones** y **verificar cada dependencia UML** antes de implementar. La navegación no lineal requiere **estado más sofisticado** en los controladores. 