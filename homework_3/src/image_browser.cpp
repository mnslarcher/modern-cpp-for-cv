#include "homework_3.h"
using html_writer::AddImage;
using html_writer::CloseRow;
using html_writer::OpenRow;

namespace image_browser {
void AddFullRow(const ImageRow& row, bool first_row) {
  OpenRow();
  AddImage(std::get<0>(row[0]), std::get<1>(row[0]), first_row);
  AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
  AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);
  CloseRow();
}

void CreateImageBrowser(const std::string& title, const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  for (std::size_t i = 0; i < rows.size(); ++i) {
    AddFullRow(rows[i], i == 0);
  }
  html_writer::CloseBody();
  html_writer::CloseDocument();
}

}  // namespace image_browser