//------------------------------------------------------------------------------
// Copyright 2019 Automation Resources Group
//------------------------------------------------------------------------------

function HandlebarsExt() {

    Handlebars.registerHelper("math", function (lvalue, operator, rvalue) {
        lvalue = parseFloat(lvalue);
        rvalue = parseFloat(rvalue);
        return {
            "+": lvalue + rvalue,
            "-": lvalue - rvalue,
            "*": lvalue * rvalue,
            "/": lvalue / rvalue,
            "%": lvalue % rvalue
        }[operator];
    });
}

$(document).on({
        change: function (event) {
            var $this = $(this);
            var $targetElement = $($this.attr('data-target'));
            $targetElement.attr($this.attr('data-target-attr'), $this.val());
        }

    },
    'input[data-target]');



const {
    remote
} = require('electron')
const {
    Menu,
    MenuItem
} = remote

//Copy PV Name from Element
$(document).on({
    contextmenu: function (event) {

        event.stopPropagation();
        event.preventDefault();
        
        // Prevent touch events from opening context menus
        if (event.originalEvent == undefined
            || event.originalEvent.sourceCapabilities == undefined
            || event.originalEvent.sourceCapabilities.firesTouchEvents === false) {
                //firesTouchEvents is currently only supported in chromium

            var menu = new Menu()
            var $this = $(this);
            var datavarname = $this.attr('data-var-name');
            const element = $('<textarea ></textarea>');

            menu.append(new MenuItem({
                label: 'Paste',
                click() {

                    document.execCommand('paste');
                }
            }))
            menu.append(new MenuItem({
                label: 'Copy PV',
                click() {
                    $this.append(element);
                    element.text(datavarname);
                    element.focus();
                    element[0].setSelectionRange(0, datavarname.length);
                    document.execCommand('copy');
                    element.remove();
                    console.log(datavarname)
                }
            }))
            menu.popup(remote.getCurrentWindow())

        }

        return false;

    }
}, '[data-var-name]');

$(document).on({
    contextmenu: function (event) {
        if (event.originalEvent == undefined
            || event.originalEvent.sourceCapabilities == undefined
            || event.originalEvent.sourceCapabilities.firesTouchEvents === false) {
            var menu = new Menu();
            menu.append(new MenuItem({
                label: 'Paste',
                click() {

                    document.execCommand('paste');
                }
            }))
            menu.popup(remote.getCurrentWindow())
        }

        event.stopPropagation();
        return false;
    }
}, 'input:not([data-var-name]),textarea:not([data-var-name]),span:not([data-var-name])');

$(document).on({
    click:function(){
        $(this).closest('.dropdown').find('.selected-item').text($(this).text());        
    }
},'.dropdown-menu a')
