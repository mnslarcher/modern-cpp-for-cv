#include "html_writer.hpp"
using html_writer::AddImage;
using html_writer::CloseRow;
using html_writer::OpenRow;

int main() {
  html_writer::OpenDocument();
  html_writer::AddTitle("Image Browser");
  html_writer::AddCSSStyle("style.css");
  html_writer::OpenBody();
  OpenRow();
  AddImage("data/000000.png", 0.98, true);
  AddImage("data/000100.png", 0.96, false);
  AddImage("data/000200.png", 0.88, false);
  CloseRow();
  OpenRow();
  AddImage("data/000300.png", 0.87, false);
  AddImage("data/000400.png", 0.80, false);
  AddImage("data/000500.png", 0.79, false);
  CloseRow();
  html_writer::CloseBody();
  html_writer::CloseDocument();
}