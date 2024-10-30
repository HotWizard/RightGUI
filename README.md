# RightGUI
### Компиляция библиотеки
Для этого Вам понадобиться:
1. Установить глобально на Вашем устройстве библиотеку [Vulkan](https://www.vulkan.org/) и долполнение [Vulkan Validation Layers (VVL)](https://github.com/KhronosGroup/Vulkan-ValidationLayers) к ней
2. Установить глобально на Вашем устройстве библиотеку любого поддерживающего [WindowsAPI](https://en.wikipedia.org/wiki/Category:Windows_APIs), поддерживающие можно посмотреть в файле [WindowsAPIs.md](WindowsAPIs.md)
2. Установить на Вашем устройстве [git](https://git-scm.com/)
3. Установить на Вашем устройстве [xmake](https://xmake.io/#/)
4. Скачать репозиторий [RightGUI](https://github.com/HotWizard/RightGUI) с помощью команды ```git clone https://github.com/HotWizard/RightGUIi && cd RightGUI```
5. Запустить команду ```xmake f --toolchain=gcc-12 -c && xmake```

Если при выполнении всех этих этапов не возникло никакаих ошибок то файл ```libRightGUI.a``` будет находиться по пути ```RightGUI/build/linux/x86_64/release```

### Компиляция тестовой программы
Для этого Вам понадобиться:
1. Перейти в папку [test](test)
2. Запустить команду ```xmake f --toolchain=gcc-12 && xmake -P .```
