const fs = require("fs");
const path = require("path");

function deleteExeFiles(directory) {
  fs.readdir(directory, (err, files) => {
    if (err) {
      console.error(`Error reading directory: ${directory}`, err);
      return;
    }
    files.forEach((file) => {
      const filePath = path.join(directory, file);

      fs.stat(filePath, (err, stats) => {
        if (err) {
          console.error(`Error getting stats for file: ${filePath}`, err);
          return;
        }
        if (stats.isDirectory()) {
          deleteExeFiles(filePath);
        } else if (file.endsWith(".exe")) {
          fs.unlink(filePath, (err) => {
            if (err) {
              console.error(`Error deleting file: ${filePath}`, err);
            } else {
              console.log(`Deleted: ${filePath}`);
            }
          });
        }
      });
    });
  });
}

const pathToYourDirectory = process.cwd();
deleteExeFiles(pathToYourDirectory);
