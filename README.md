# 🏪 Sistema OXXO – Simulación de Punto de Venta en C++

Proyecto académico desarrollado en **C++** que simula un sistema básico de gestión tipo **OXXO**, enfocado en **buenas prácticas de programación**, **Programación Orientada a Objetos** y una **arquitectura limpia y profesional**.

Este proyecto fue **refactorizado completamente** con el objetivo de que sea **publicable como portafolio profesional**, no solo como una práctica escolar.

---

## 🎯 Objetivo del proyecto

Simular un **sistema de punto de venta** que permita:

- 👤 Gestión de clientes  
- 🏭 Gestión de proveedores  
- 📦 Gestión de productos  
- 💰 Venta de productos con control de inventario  
- ⚠️ Manejo robusto de errores y validaciones  

Todo aplicando principios sólidos de diseño en **C++ moderno**.

---

## 🧱 Arquitectura y conceptos aplicados

Este proyecto hace uso de:

- 🧠 **Programación Orientada a Objetos (POO)**
- 🧩 **Clases abstractas** (`Producto`)
- 🔁 **Polimorfismo**
- 🔐 **Smart Pointers** (`std::unique_ptr`)
- 📚 **STL** (`unordered_map`, `vector`, `optional`)
- 🚨 **Manejo de excepciones personalizadas**
- 🧼 **Separación clara de responsabilidades**
- 📁 **Estructura profesional de proyecto (`include/` y `source/`)**

---

## 📂 Estructura del proyecto

```text
SistemaOxxo/
│
├── include/
│   ├── Cliente.h
│   ├── Proveedor.h
│   ├── Producto.h
│   ├── ProductoBebida.h
│   ├── ProductoSnack.h
│   ├── SistemaOxxo.h
│   ├── Menu.h
│   ├── Input.h
│   └── OxxoException.h
│
├── source/
│   ├── SistemaOxxo.cpp
│   ├── Menu.cpp
│   └── main.cpp
│
└── README.md

---

## ⚙️ Funcionalidades principales

### 👤 Clientes
- Registrar clientes  
- Eliminar clientes  
- Listar clientes  
- Gestión de puntos  

### 🏭 Proveedores
- Registrar proveedores  
- Asociar productos a proveedores  
- Listar proveedores  

### 📦 Productos
- Registro de productos por tipo:
  - 🥤 **Bebidas** (con impuesto si son azucaradas)
  - 🍫 **Snacks** (con recargo si son importados)
- Control de inventario (stock)
- Uso de polimorfismo para el cálculo del precio final  

### 💰 Ventas
- Venta con o sin cliente  
- Validación de stock disponible  
- Manejo de errores en tiempo de ejecución  

---

## 🚨 Manejo de errores

El sistema implementa una excepción personalizada (`OxxoException`) para manejar casos como:

- ❌ Productos duplicados  
- ❌ Clientes inexistentes  
- ❌ Stock insuficiente  
- ❌ Entradas inválidas del usuario  

Esto mejora la **robustez**, **seguridad** y **legibilidad** del sistema.

---

## 🧠 Decisiones de diseño relevantes

- Se utiliza `std::unique_ptr` para garantizar **propiedad única** de los productos y evitar fugas de memoria.
- La clase abstracta `Producto` permite extender el sistema con nuevos tipos sin modificar la lógica central.
- `SistemaOxxo` funciona como capa de negocio, separada del menú y del input.
- El sistema prioriza **claridad y mantenibilidad** sobre complejidad innecesaria.

---

## ▶️ Cómo compilar y ejecutar

### 🛠 Requisitos
- **Visual Studio 2022**
- Estándar **C++17**

### 🚀 Pasos
1. Abrir el proyecto en Visual Studio
2. Verificar que el estándar sea **ISO C++17**
3. Compilar la solución
4. Ejecutar el programa desde la consola

---

## 📌 Estado del proyecto

✅ Funcional  
✅ Compila sin errores  
✅ Arquitectura estable  
✅ Código limpio y refactorizado  
✅ Listo para portafolio profesional  

---

## 🚀 Posibles mejoras futuras

- Persistencia de datos (guardar/cargar clientes y productos)
- Pruebas unitarias
- Interfaz gráfica
- Reportes de ventas

---

## 👨‍💻 Autor

**Kevin Jair Chávez Castro**  
Ingeniero en Desarrollo de Videojuegos y Medios Interactivos, con enfoque en **programación en C++**, **arquitectura de sistemas**, y **desarrollo de aplicaciones interactivas**.

