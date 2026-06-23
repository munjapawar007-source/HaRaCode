#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define _use_MATH_DEFINES 1


// OGL Related File
#include<GL/glew.h>
#include<gl/GL.h>
#include"OGL.h"
#include"vmath.h"
using namespace vamth;

// OpenGL Related Libraries
#pragma comment(lib,"glew32.lib")
#pragma comment(lib, "opengl32.lib")

// MICROS
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// GLOBAL Function Declaration/protoype/signature
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Decalaration
// fullscreen related
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;      // to hold value
WINDOWPLACEMENT wpPrev;

// File I/O releted
char gszLogFileName[] = "Log.txt";
FILE* gpFile = NULL;

// Active window related
BOOL gbActiveWindow = FALSE;

// Exit keyPress Related Variable
BOOL gbEscapeKeyPressed = FALSE;

// openGL relateld veriables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

// shader related 
GLuint shaderProgramObject = 0;

enum
{
    AMC_ATTRIBUTE_POSITION = 0,
    AMC_ATTRIBUTE_COLOR,
};

GLuint vao = 0;
GLuint vbo = 0;
GLuint vbo_color = 0;

mat4 perspectiveProjectionMatrix;

// entry point func
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // function 
    int initialize(void);
    void display(void);
    void update(void);
    void unitialize(void);

    // Variable Declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR6");
    BOOL bDone = FALSE;

    // code 
    gpFile = fopen(gszLogFileName, "w");
    if(gpFile == NULL)
    {
        massageBox(NULL, TEXT("Log File Creation Failed"), TEXT("ERROR"), MB_OK);
        exit(0);
    }
    else
    {
        fprintf(gpFile, "Program Stared Successfully.\n");
    }

    // window class Initialization
    wndclass.cbSize = sizof(WNDCLASSEX);
    wndclass.style  = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // owndc self device context
    wndclass.cbCLsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm  = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // Registration of window class
    RegisterClassEX(&wndclass);

    // create window center
    int m_x = (GetSystemMetrics(SM_CXSCREEN) - WIN_WIDTH)/2; 
    int m_x = (GetSystemMetrics(SM_CYSCREEN) - WIN_HEIGHT)/2;

    // create window
    hwnd = CreateWindow(WS_EX_APPWINDOW, szAppName, TEXT("mp"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, m_x, m_y, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

    ghwnd = hwnd;

    //show window
    ShowWindow(hwnd, iCmdShow);

    // paint background window
    UpdateWindow(hwnd);

    // initialize
    if(initialize() != 0)
    {
        fprintf(gpFile, "initialize Failed\n");
        DestroyWindow(ghwnd);
        ghwnd = NULL;
    }
    else
    {
        fprintf(gpFile, "Initialize() Function completed successfully..\n");
    }

    // set this window as foreground and active window
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);

    // game loop
    while(bDone == FALSE)
    {
        if(PeekMassage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
            {
                bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

        }
        else
        {
            if(gbActiveWindow == TRUE)
            {
                if(gbEscapeKeyPressed == TRUE)
                {
                    bDone = TRUE;
                }

                // render
                display();

                // update
                update();
            }
        }
    }

    // uninitialize
    uninitialize();

    return((int)msg.wParam);
}

// call back function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lparam)
{
    // function declaration
    void toggleFullScreen(void);
    void resize(int int);
    void uninitialize(void);

    // code
    switch(iMsg)
    {
        case WM_CREATE: 
            ZeroMemory((void*)&wpPrev, sizeof(WINDOWPLACEMENT));
            wpPrev.length = sizeof(WINDOWPLACEMENT);
            break;
        case WM_SETFOCUS:
            gbActiveWindow = TRUE;
            break;
        case WM_KILLFOCUS:
            gbActiveWindow = FALSE;
            break;
        case: WM_ERASEBKGND:    // for smooth rendaring
            return(0);
        case WM_SIZE:
            resize(LOWORD(lparam), HIWORD(lparam));
            break;
        case WM_KEYDOWN:
            switch(wparam)
            {
                case VK_ESCAPE:
                gbEscapeKeyPressed = TRUE;
                DestroyWindow(ghwnd);
                break;
                default:
                break;
            }
            break;
        case WM_CHAR:
            switch (wparam)
            {
            case 'f':
            case 'F':
                if(gbFullScreen == FALSE)
                {
                    toggleFullScreen();
                    gbFullScreen =TRUE;
                }
                else
                {
                    toggleFullScreen();
                    gbFullScreen = FALSE;
                }
                break;
            default:
                break;
            }
            break;
        case WM_CLOSE:
            uninitialize();
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            break;
    }
   
    return(DefWindowProc(hwnd, iMsg, wparam, lparam));
}

void toggleFullScreen(void)
{
    // variable declaration
    MONITORINFO mi;

    if(gbFullScreen == FALSE)
    {
        dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

        if(dwStyle & WS_OVERLAPPEDWINDOW)
        {
            ZeroMemory((void*)&mi, sizeof(MONITORINFO));
            mi.cbSize = sizeof(MONITORINFO);

            if(GetWindowPlacement(ghwnd, &wpPrev) && GwtMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
            {
                SetWindowLong(ghwnd, GWL_STYLE, dwStyle, & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(ghwnd, HWND_TOP, Mi,rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
            }

        }
        ShowCursor(FALSE);
    }
    else
    {
        SetWindowPlacement(ghwnd, &wpPrev);
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER |SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }
}

int initialize(void)
{
    // function declaration
    void printGLINFO();
    void resize(int, int);
    void uninitialize();

    // Variable Declarations
    PIXELFORMATDESCRIPTOR pfd;
    int iPixelFormatIndex = 0;
    GLenum glewResult;

    // code
    ZeroMemory((void*)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cRedBits = 8;
    pfd.cGreenBits = 8;
    pfd.cBlueBits = 8;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 32;

    // getDc
    ghdc = GetDC(ghwnd);

    if(ghdc == NULL)
    {
        fPrintf(gpFile, "Get dc Function failed\n");
        return(-1);
    }

    // get matching pixel format Index Using HDC and Pfd
    iPixelFormatIndex = choosePixelFormat(ghdc, &pfd);
    
    if(iPixelFormatIndex == 0)
    {
        fprintf(gpFile, "ChoosePixelFormat func Failed \n");
        return(-2);
    }

    // select this pixel format of found index
    if(SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        fprintf(gpFile,"choosepixelformat func failed\n");
        return(-3)
    }

    // briging api (wsi-window system integration)
    // create rendaring context using ghdc, pfd, choosePixelFormat

    ghrc = wglCreateContext(ghdc);
    if(ghrc == NULL)
    {
        fprintf(gpFile,"wglCreateContext func failed\n");
        return(-4);
    }

    // make this rendering context as current context
    if(wglMakeCurrent(ghd, ghrc) == FALSE)
    {
        fprintf(gpFile,"wglMakeCurrent func failed\n");
        return(-5);
    }

    // GLEW
    glewResult = glewInit();
    if(glewResult != GLEW_OK)
    {
        fprintf(gpFile," glewInit Failed\n");
    }

    printGLINFO();
    s
    // vertex shader
    const GLchar* vertexShaderSourceCode = 
    "#version 460 core\n" \
    "in vec4 aPosition;\n" \
    "in vec4 aColor;\n" \
    "out vec4 out_color;\n" \
    "uniform mat4 uMVPMatrix;\n" \
    "void main(void)\n" \
    "{\n" \
        "gl_position = uMVPMatrix * aPosition;\n"
        "out_color = aColor;\n" \
    "}\n";

    GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);

    glCompileShader(vertexShaderObject);



}