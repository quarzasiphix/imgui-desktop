// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs
#include <common.hpp>
// Main code
int main(int, char**) {
    GLFWwindow* window;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Initialize GLFW
    if (!glfwInit()) {
        return 1;
    }

    if (glewIsSupported("GL_VERSION_3_3")) {
        // Set OpenGL version to 4.5
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        printf("using ver 3.3");
    }
    else if (glewIsSupported("GL_VERSION_2_1")) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        printf("using ver 2.1");
    }
    else {
        // No supported version of OpenGL found
        printf("No supported version of OpenGL found, trying 3.3\n");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    }

    gui my_gui;

    my_gui.window = glfwCreateWindow(800, 600, "imgui desktop", NULL, NULL);

    // Make the window's context current
    glfwMakeContextCurrent(my_gui.window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        std::cin.get();
        return 1;
    }
    
    if (!my_gui.init()) {
        printf("failed to start imgui");
        return 1;
    }

    while (!glfwWindowShouldClose(my_gui.window)) {
        // Poll for and process events
        glfwPollEvents();


        my_gui.run();

        //Swap front and back buffers 
        glfwSwapBuffers(my_gui.window);
    }

    // Cleanup
    
    my_gui.~gui();
    
    glfwDestroyWindow(my_gui.window);
    glfwTerminate();
}



/*  working code, broken viewport and docking tho lol
 GLFWwindow* window;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Initialize GLFW
    if (!glfwInit()) {
        return 1;
    }

    if (glewIsSupported("GL_VERSION_3_3")) {
        // Set OpenGL version to 4.5
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        printf("using ver 3.3");
    }
    else if (glewIsSupported("GL_VERSION_2_1")) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        printf("using ver 2.1");
    }
    else {
        // No supported version of OpenGL found
        printf("No supported version of OpenGL found, trying 3.3\n");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    }

    

    window = glfwCreateWindow(800, 600, "imgui desktop", NULL, NULL);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        std::cin.get();
        return 1;
    }

    // Setup ImGui context
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    if (glewIsSupported("GL_VERSION_3_3")) ImGui_ImplOpenGL3_Init("#version 330");
    else if (glewIsSupported("GL_VERSION_2_1")) ImGui_ImplOpenGL3_Init("#version 120");
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui::StyleColorsDark();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    while (!glfwWindowShouldClose(window)) {
        // Poll for and process events
        glfwPollEvents();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT); // clear color buffer with the specified color

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // Set up dockspace
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiDockNodeFlags_NoCloseButton | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiColumnsFlags_NoResize | ImGuiWindowFlags_NoDocking;
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            dockspace_flags |= ImGuiDockNodeFlags_PassthruCentralNode;
            window_flags |= ImGuiWindowFlags_NoBackground;
        }
        ImGui::SetNextWindowSize(ImVec2((float)display_w, (float)display_h));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("Dockspace", nullptr, window_flags);
        ImGui::DockSpace(ImGui::GetID("MyDockspace"), ImVec2(0.0f, 0.0f), dockspace_flags);

        // Add menu bar
        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                ImGui::MenuItem("Save", NULL);
                ImGui::MenuItem("Exit", NULL);
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::Begin("yo");

        ImGui::Text("sup");
        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        //Swap front and back buffers 
        glfwSwapBuffers(window);
        }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();


*/