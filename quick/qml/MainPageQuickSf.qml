import QtQuick 2.0
import Sailfish.Silica 1.0
import Qt5Mozilla 1.0

ApplicationWindow {

    initialPage: browserPage
    cover: null
    allowedOrientations: Orientation.Portrait

    Page {
        id: browserPage


        QmlMozView {
            id: view1

            width: parent.width
            height: parent.height
            active: true
            clip: true

            onViewInitialized: {
                loadFrameScript("chrome://embedlite/content/embedhelper.js")
                //load("http://www.google.com")
                //load("about:license")
                load("http://iltasanomat.fi")
            }
        }
    }
}
