void build() {
  hub.Menu(F("Dashboard,Settings,Setup,Info"));

  switch (hub.menu) {

    case 0:
      {  //Dashboard
        //hub.WidgetSize(100);
        hub.Label(F("Label "));
        hub.Title(F("Title"));
        hub.Input(&mydata.apSsid, GH_STR, F("AP SSID"));

        // и выведем пару компонентов
        hub.Slider();
        hub.Input();
        hub.Switch();
      }
      break;

    case 1:
      {  //Settings
      }
      break;

    case 2:
      {  //Setup
      }
      break;

    case 3:
      {  //Info
      }
      break;
  }
}
