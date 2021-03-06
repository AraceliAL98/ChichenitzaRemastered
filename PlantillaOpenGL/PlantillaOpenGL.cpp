// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include "Shader.h"
#include "Vertice.h"

using namespace std;

Shader *shader;
GLuint posicionID;
GLuint colorID;

vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

void inicializarCuadrado() {

	//Escalon 1
	Vertice v1 = {
		vec3(-0.8, -0.8, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v2 = {
		vec3(0.8, -0.8, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v3 = {
		vec3(0.8, -0.95, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v4 = {
		vec3(-0.8, -0.95, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);

	//Escalon 2
	Vertice v5 = {
		vec3(-0.7, -0.65, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v6 = {
		vec3(0.7, -0.65, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v7 = {
		vec3(0.7, -0.8, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v8 = {
		vec3(-0.7, -0.8, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v5);
	cuadrado.push_back(v6);
	cuadrado.push_back(v7);
	cuadrado.push_back(v8);

	//Escalon 3
	Vertice v9 = {
		vec3(-0.61, -0.65, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v10 = {
		vec3(0.61, -0.65, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v11 = {
		vec3(0.61, -0.5, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v12 = {
		vec3(-0.61, -0.5, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v9);
	cuadrado.push_back(v10);
	cuadrado.push_back(v11);
	cuadrado.push_back(v12);

	//Escalon 4
	Vertice v13 = {
		vec3(-0.53, -0.35, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v14 = {
		vec3(0.53, -0.35, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v15 = {
		vec3(0.53, -0.5, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v16 = {
		vec3(-0.53, -0.5, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v13);
	cuadrado.push_back(v14);
	cuadrado.push_back(v15);
	cuadrado.push_back(v16);

	//Escalon 5
	Vertice v17 = {
		vec3(-0.45, -0.35, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v18 = {
		vec3(0.45, -0.35, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v19 = {
		vec3(0.45, -0.20, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v20 = {
		vec3(-0.45, -0.20, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v17);
	cuadrado.push_back(v18);
	cuadrado.push_back(v19);
	cuadrado.push_back(v20);

	//Escalon 6
	Vertice v21 = {
		vec3(-0.38, -0.05, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v22 = {
		vec3(0.38, -0.05, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v23 = {
		vec3(0.38, -0.20, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v24 = {
		vec3(-0.38, -0.20, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v21);
	cuadrado.push_back(v22);
	cuadrado.push_back(v23);
	cuadrado.push_back(v24);

	//Escalon 7
	Vertice v25 = {
		vec3(-0.31, -0.05, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v26 = {
		vec3(0.31, -0.05, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v27 = {
		vec3(0.31, 0.10, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v28 = {
		vec3(-0.31, 0.10, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v25);
	cuadrado.push_back(v26);
	cuadrado.push_back(v27);
	cuadrado.push_back(v28);

	//Escalon 8
	Vertice v29 = {
		vec3(-0.25, 0.25, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v30 = {
		vec3(0.25, 0.25, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v31 = {
		vec3(0.25, 0.10, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v32 = {
		vec3(-0.25, 0.10, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v29);
	cuadrado.push_back(v30);
	cuadrado.push_back(v31);
	cuadrado.push_back(v32);

	//Cuadro de arriba
	Vertice v33 = {
		vec3(-0.18, 0.25, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v34 = {
		vec3(0.18, 0.25, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v35 = {
		vec3(0.18, 0.55, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	Vertice v36 = {
		vec3(-0.18, 0.55, 0.0),
		vec4(0.92, 0.80, 0.42, 1.0)
	};
	cuadrado.push_back(v33);
	cuadrado.push_back(v34);
	cuadrado.push_back(v35);
	cuadrado.push_back(v36);

	Vertice v37 = {
		vec3(-0.18, 0.50, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v38 = {
		vec3(0.18, 0.50, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v39 = {
		vec3(0.18, 0.55, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v40 = {
		vec3(-0.18, 0.55, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	cuadrado.push_back(v37);
	cuadrado.push_back(v38);
	cuadrado.push_back(v39);
	cuadrado.push_back(v40);

	Vertice v41 = {
		vec3(-0.18, 0.45, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v42 = {
		vec3(0.18, 0.45, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v43 = {
		vec3(0.18, 0.40, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v44 = {
		vec3(-0.18, 0.40, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	cuadrado.push_back(v41);
	cuadrado.push_back(v42);
	cuadrado.push_back(v43);
	cuadrado.push_back(v44);

	Vertice v45 = {
		vec3(-0.03, 0.25, 0.0),
		vec4(0.1, 0.1, 0.1, 1.0)
	};
	Vertice v46 = {
		vec3(0.03, 0.25, 0.0),
		vec4(0.1, 0.1, 0.1, 1.0)
	};
	Vertice v47 = {
		vec3(0.03, 0.38, 0.0),
		vec4(0.1, 0.1, 0.1, 1.0)
	};
	Vertice v48 = {
		vec3(-0.03, 0.38, 0.0),
		vec4(0.1, 0.1, 0.1, 1.0)
	};
	cuadrado.push_back(v45);
	cuadrado.push_back(v46);
	cuadrado.push_back(v47);
	cuadrado.push_back(v48);
	
	//Escaleras (?)
	Vertice v49 = {
		vec3(-0.18, 0.25, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v50 = {
		vec3(-0.12, 0.25, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v51 = {
		vec3(-0.14, -0.95, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v52 = {
		vec3(-0.20, -0.95, 0.0),
		vec4(0.79, 0.66, 0.35, 1.0)
	};
	cuadrado.push_back(v49);
	cuadrado.push_back(v50);
	cuadrado.push_back(v51);
	cuadrado.push_back(v52);

	Vertice v53 = {
		vec3(0.18, 0.25, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v54 = {
		vec3(0.12, 0.25, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v55 = {
		vec3(0.14, -0.95, 0.0),
		vec4(0.8, 0.57, 0.3, 1.0)
	};
	Vertice v56 = {
		vec3(0.20, -0.95, 0.0),
		vec4(0.79, 0.66, 0.35, 1.0)
	};
	cuadrado.push_back(v53);
	cuadrado.push_back(v54);
	cuadrado.push_back(v55);
	cuadrado.push_back(v56);
}

void inicializarTriangulo() {
	Vertice v1 = {
		vec3(0.0f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};
	Vertice v2 = {
		vec3(-0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};
	Vertice v3 = {
		vec3(0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void dibujar() {
	//Elegir el shader
	shader->enlazar();
	//Elegir un vertex array 
	glBindVertexArray(vertexArrayTrianguloID);
	//dibujar 
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	//Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	//soltar el vertex array
	glBindVertexArray(0);
	//soltar el shader
	shader->desenlazar();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//si no se pudo inicializar glfw terminamos ejecución
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//si se pudo iniciar GLFW entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 600, "Ventana", NULL, NULL);

	//si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//UNa vez establecido el contexto activamos funciones modernas (CPU/GPU)
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	inicializarTriangulo();
	inicializarCuadrado();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();

	//crear un vertex array
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);
	//crear vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Vertex array y buffer para cuadrado
	//crear un vertex array
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	//crear vertex buffer
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//especificar a OpenGL como se va a comunicar
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice),  (void*)sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Cilco de dibijo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 600);
		//Esctablece el color de borrado
		glClearColor(0, 0, 0.5, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

