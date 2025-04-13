<?php
// Start the session
session_start();

// Destroy all session variables
session_unset();

// Destroy the session
session_destroy();

echo "Session has been destroyed.<br>";
echo "Click <a href='sessionstart.php'>here</a> to start a new session.";
?>
