#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip>

/**
 * Muda a largura e altura de acordo com a alteração da janela em tempo real
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "[WIDTH] : " << width << " [HEIGHT] : " << height << std::endl;
}
/**
 * Faz o processamento dos inputs gerados pela window
 */
void processInput(GLFWwindow *window)
{
    /* Utiliza a Tecla ESC para fechar a aplicação*/
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**
 * Configuração da windows, especificando seus compoenentes e ferramentais,
 * - glfw window
 * - glad
 */
int main()
{
    /* Configurações do glfw */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Criação de uma janela com glfw*/
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    /* Verificação de criação da janela*/
    if (window == NULL)
    {
        std::cout << "Failed to create a GLFW window" <<  std::endl;
        glfwTerminate();
        return -1;
    }
    /* Define a janela como contexto da inicialização*/
    glfwMakeContextCurrent(window);
    std::cout << "GLFW [CREATED WINDOW]" <<  std::endl;
    /* Inicialização do glad para que ele controle os ponteiros das funções do openGL*/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    std::cout << "GLAD [INITIALIZED]" <<  std::endl;  
    /* Define espaço de desenho dentro da janela*/
    glViewport(0, 0, 800, 600);
    /* Define a função para mudança dos valores de altura e largura da janela*/
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    /* Loop para manter a janela aberta*/
    while(!glfwWindowShouldClose(window)){
        /* Process inputs ---------------------------------------------------*/
        processInput(window);

        /* Rendering commands -----------------------------------------------*/
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /*RGBA com intervalo de 0 a 1*/
        glClear(GL_COLOR_BUFFER_BIT);

        /* Checagem e mudança de eventos e mudança do buffer ----------------*/
        /* Muda as cores de cada pixel de acordo com o buffer*/
        glfwSwapBuffers(window);
        /* Verifica os eventos que ocorrem no mouse ou no teclado*/
        glfwPollEvents();
    }
    glfwTerminate();
    std::cout << "GLFW [TERMINATED]" <<  std::endl;
    return 0;
}