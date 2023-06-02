#include <opencv2/opencv.hpp>
#include <fstream>
#include </usr/include/jsoncpp/json/json.h>

int main()
{
    // Création de la fenêtre
    cv::namedWindow("Rotation Animation", cv::WINDOW_NORMAL);

    // Chargement de l'image
    cv::Mat image = cv::imread("/home/c4/Codes/image/panda_1.jpg");

    // Vérification si l'image est valide
    if (image.empty())
    {
        std::cout << "Impossible de charger l'image!" << std::endl;
        return -1;
    }

    // Lecture du fichier JSON
    std::ifstream jsonFile("/home/c4/Codes/json/image1.json");
    Json::Value root;
    jsonFile >> root;

    // Vérification de la structure JSON
    if (!root.isObject() ||
        !root.isMember("setting") ||
        !root["setting"].isObject() ||
        !root["setting"].isMember("image1") ||
        !root["setting"]["image1"].isObject() ||
        !root["setting"]["image1"].isMember("animation") ||
        !root["setting"]["image1"]["animation"].isObject() ||
        !root["setting"]["image1"]["animation"].isMember("rotation") ||
        !root["setting"]["image1"]["animation"]["rotation"].isObject() ||
        !root["setting"]["image1"]["animation"]["rotation"].isMember("speed") ||
        !root["setting"]["image1"]["animation"]["rotation"]["speed"].isString() ||
        !root["setting"]["image1"]["animation"]["rotation"].isMember("direction") ||
        !root["setting"]["image1"]["animation"]["rotation"]["direction"].isString())
    {
        std::cout << "Structure JSON invalide!" << std::endl;
        return -1;
    }

    // Récupération des valeurs "speed" et "direction" du fichier JSON
    std::string speedStr = root["setting"]["image1"]["animation"]["rotation"]["speed"].asString();
    std::string directionStr = root["setting"]["image1"]["animation"]["rotation"]["direction"].asString();

    // Conversion de la vitesse en double
    double speed;
    if (speedStr == "fast") {
        speed = 2.0;
    }
    else if (speedStr == "medium") {
        speed = 1.0;
    }
    else if (speedStr == "slow") {
        speed = 0.5;
    }
    else {
        // Valeur par défaut en cas de valeur inconnue
        speed = 1.0;
    }

    // Définition de la direction de rotation en fonction de la valeur "direction"
    double angle;
    if (directionStr == "clockwise") {
        angle = -45;
    }
    else if (directionStr == "counter-clockwise") {
        angle = 45;
    }
    else {
        // Valeur par défaut en cas de valeur inconnue
        angle = -45;
    }

    // Calcul du centre de rotation
    cv::Point2f center(image.cols / 2.0, image.rows / 2.0);

    // Mettre la fenêtre en plein écran
    cv::setWindowProperty("Rotation Animation", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    // Boucle d'animation
    while (true)
    {
        // Création d'une copie de l'image originale
        cv::Mat rotatedImage = image.clone();

        // Calcul de l'angle de rotation pour chaque itération
        double currentAngle = (angle * speed) * cv::getTickCount() / cv::getTickFrequency();

        // Réalisation de la rotation
        cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, currentAngle, 1.0);
        cv::warpAffine(image, rotatedImage, rotationMatrix, image.size());

        // Affichage de l'image
        cv::imshow("Rotation Animation", rotatedImage);

        // Vérification si l'utilisateur a appuyé sur la touche 'Esc'
        if (cv::waitKey(1) == 27)
            break;
    }

    // Fermeture de la fenêtre
    cv::destroyAllWindows();

    return 0;
}