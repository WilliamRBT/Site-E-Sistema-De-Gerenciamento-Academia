import React from 'react';
import { Mail, Phone, MapPin } from 'lucide-react';

const ContactPage: React.FC = () => {
  return (
    <div className="bg-[#121212] text-gray-200 min-h-screen pt-24"> {/* Added pt-24 for header clearance */}
      <div className="container mx-auto px-6 py-16">
        <div className="text-center mb-16">
          <h2 className="text-4xl md:text-5xl font-black text-white">Fale Conosco</h2>
          <p className="text-lg text-gray-400 mt-4 max-w-2xl mx-auto font-light">
            Estamos aqui para ajudar! Entre em contato para dúvidas, sugestões ou para agendar uma visita.
          </p>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-12 items-center">
          {/* Contact Information */}
          <div className="bg-[#1a1a1a] p-10 rounded-xl border border-gray-800 shadow-lg">
            <h3 className="text-3xl font-bold text-orange-500 mb-6">Informações de Contato</h3>
            <div className="space-y-6 text-gray-300">
              <div className="flex items-center">
                <Mail className="text-orange-500 mr-4" size={24} />
                <p className="text-lg">contato@gymelite.com</p>
              </div>
              <div className="flex items-center">
                <Phone className="text-orange-500 mr-4" size={24} />
                <p className="text-lg">(11) 98765-4321</p>
              </div>
              <div className="flex items-start">
                <MapPin className="text-orange-500 mr-4 mt-1" size={24} />
                <p className="text-lg">Rua Supino Torto, 000 - Centro, São Paulo - SP</p>
              </div>
            </div>
            <div className="mt-10">
              <h4 className="text-xl font-semibold text-white mb-4">Horário de Funcionamento</h4>
              <p className="text-gray-400">Segunda a Sexta: 06:00 - Até o último aluno aguentar</p>
              <p className="text-gray-400">Sábado: 08:00 - 18:00</p>
              <p className="text-gray-400">Domingo: Fechado</p>
            </div>
          </div>

          {/* Contact Form */}
          <div className="bg-[#1a1a1a] p-10 rounded-xl border border-gray-800 shadow-lg">
            <h3 className="text-3xl font-bold text-white mb-6">Envie uma Mensagem</h3>
            <form className="space-y-6">
              <div>
                <label htmlFor="name" className="block text-gray-400 text-sm font-medium mb-2">Nome Completo</label>
                <input
                  type="text"
                  id="name"
                  className="w-full p-3 bg-gray-900 border border-gray-700 rounded-md text-white focus:outline-none focus:ring-2 focus:ring-orange-500"
                  placeholder="Seu nome"
                />
              </div>
              <div>
                <label htmlFor="email" className="block text-gray-400 text-sm font-medium mb-2">Email</label>
                <input
                  type="email"
                  id="email"
                  className="w-full p-3 bg-gray-900 border border-gray-700 rounded-md text-white focus:outline-none focus:ring-2 focus:ring-orange-500"
                  placeholder="seu.email@exemplo.com"
                />
              </div>
              <div>
                <label htmlFor="message" className="block text-gray-400 text-sm font-medium mb-2">Mensagem</label>
                <textarea
                  id="message"
                  rows={5}
                  className="w-full p-3 bg-gray-900 border border-gray-700 rounded-md text-white focus:outline-none focus:ring-2 focus:ring-orange-500"
                  placeholder="Sua mensagem..."
                ></textarea>
              </div>
              <button
                type="submit"
                className="w-full bg-orange-500 text-white font-bold text-lg py-3 rounded-md uppercase tracking-wider hover:bg-orange-600 transition-all duration-300 transform hover:scale-105 shadow-lg shadow-orange-500/20"
              >
                Enviar Mensagem
              </button>
            </form>
          </div>
        </div>
      </div>
    </div>
  );
};

export default ContactPage;