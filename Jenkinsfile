pipeline {
    agent {
        // Specify a label that defines the type of agent that can be used for this build
        label 'windows-automation-studio' // TODO: This does not require AS but does require node
    }
    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                bat 'npm install'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                bat 'npm run test'
            }
        }
        // stage('Deploy') {
        //     steps {
        //         echo 'Deploying....'
        //     }
        // }
    }
}