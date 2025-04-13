<?php
$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
if (isset($_POST["submit"]) && getimagesize($_FILES["fileToUpload"]["tmp_name"])) {
    if ($_FILES["fileToUpload"]["size"] > 5000000) {
        echo "Sorry, your file is too large.";
    } else {
        if (in_array($imageFileType, ['jpg', 'jpeg', 'png', 'gif'])) {
            if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
                echo "The file has been uploaded.";
            } else {
                echo "Sorry, there was an error uploading your file.";
            }
        } else {
            echo "Sorry, only JPG, JPEG, PNG, & GIF files are allowed.";
        }
    }
} else {
    echo "File is not an image.";
}
?>
