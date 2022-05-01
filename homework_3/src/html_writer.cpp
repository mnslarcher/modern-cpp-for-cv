#include "html_writer.hpp"

#include <fmt/format.h>

#include <filesystem>

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
  fmt::print("      <div class=\"column\"");
  if (highlight) fmt::print(" style=\"border: 5px solid green;\"");

  fmt::print(">\n");
  std::string file_name = std::filesystem::path(img_path).filename();
  fmt::print("        <h2>{}</h2>\n", file_name);
  fmt::print("        <img src =\"{}\" />\n", img_path);
  fmt::print("        <p>score = {:.2f}</p>\n", score);
  fmt::print("      </div>\n");
}
}  // namespace html_writer