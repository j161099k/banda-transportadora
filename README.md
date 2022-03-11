<style>
    * {
        background-color: #DBDBDB;
        color: #242323;
    }
    h1 {
     border: none;
    }

    img {
        width: 10rem;
        height: 7rem;
    }
    .comment {
        color: #525151;
    }
    .main {
        border-left: 0.75rem solid #01969C;
    }
</style>

# Banda Transportadora 

![](https://cdn.worldvectorlogo.com/logos/arduino.svg)

### Este proyecto fue creado para la materia Integradora 2 de la carrera MASTMF

## Estructura

<div class="main">
<h5 style="padding-left: 0.2rem;">La estructura del projecto es la siguiente:</h5>

- Banda-Transportadora
  - include <span class="comment">// Directorio que contiene la definición de funciones y constantes necesarias en el proyecto</span>
    - ConstantDefinitions.h <span class="comment">// Define constantes que controlan la configuración del proyecto</span>
    - HelperFunctions.h <span class="comment">// Define funciones (subrutinas) que encapsulan una funcionalidad para su facil reutilización</span>
  - src <span class="comment">// Contiene el archivo principal</span>
    - main.cpp <span class="comment">// Archivo principal que ejecuta todo el código del proyecto</span>
  - test <span class="comment">// Directorio para tests unitarios</span>
</div>