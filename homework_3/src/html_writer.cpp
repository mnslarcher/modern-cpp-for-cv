#include <fmt/format.h>

#include <filesystem>

#include "homework_3.h"

namespace html_writer {
void OpenDocument() {
  fmt::print("<!DOCTYPE html>\n");
  fmt::print("<html>\n");
}

void CloseDocument() { fmt::print("</html>\n"); }

void AddCSSStyle(const std::string& stylesheet) {
  fmt::print("  <head>\n");
  fmt::print("    <link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" />\n",
             stylesheet);
  fmt::print("  </head>\n");
}

void AddTitle(const std::string& title) {
  fmt::print("  <title>{}</title>\n", title);
}

void OpenBody() { fmt::print("  <body>\n"); }

void CloseBody() { fmt::print("  </body>\n"); }

void OpenRow() { fmt::print("    <div class=\"row\">\n"); }

void CloseRow() { fmt::print("    </div>\n"); }

void AddImage(const std::string& img_path, float score, bool highlight) {
  const std::filesystem::path path = std::filesystem::path(img_path);
  const std::string extension = path.extension();
  const std::string filename = path.filename();
  if (extension.compare(".png") != 0 and extension.compare(".jpg") != 0)
    fmt::print(stderr, "The file extension must be .png or .jpg, got {}.",
               extension);

  fmt::print("      <div class=\"column\"");
  if (highlight) fmt::print(" style=\"border: 5px solid green;\"");
  fmt::print(">\n");
  fmt::print("        <h2>{}</h2>\n", filename);
  fmt::print("        <img src =\"{}\" />\n", img_path);
  fmt::print("        <p>score = {:.2f}</p>\n", score);
  fmt::print("      </div>\n");
}
}  // namespace html_writer